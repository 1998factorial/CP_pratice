#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , K;
    cin >> N >> K;
    vector<int> c(N * K + 5) , taken(N + 1);
    vector<vector<int>> pos(N + 1);
    for(int i = 1; i <= N * K; ++i){
        cin >> c[i];
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N * K; ++j){
            if(c[j] == i){
                pos[i].push_back(j);
            }
        }
    }
    vector<pii> ans(N + 1);
    int step = N / (K - 1) + (N % (K - 1) != 0);
    int cnt = 0;
    for(int chunk = 0; chunk < K - 1; ++chunk){
        vector<int> id;
        for(int i = 1; i <= N; ++i){
            id.push_back(i);
        }
        sort(id.begin() , id.end() , [&](int& l , int& r){
            return pos[l][chunk + 1] < pos[r][chunk + 1];
        });
        int ntaken = 0;
        for(int i = 1; i <= N; ++i){
            if(taken[id[i - 1]])continue;
            taken[id[i - 1]] = 1;
            ++cnt;
            ++ntaken;
            ans[id[i - 1]] = make_pair(pos[id[i - 1]][chunk] , pos[id[i - 1]][chunk + 1]);
            if(ntaken >= step)break;
        }
    }
    for(int i = 1; i <= N; ++i){
        cout << ans[i].x << " " << ans[i].y << endl;
    }
} 
