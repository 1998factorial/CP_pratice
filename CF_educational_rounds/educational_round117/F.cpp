#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , M , Q , sp = 0;
    cin >> N >> M >> Q;
    if(N < M)swap(N , M) , sp = 1;
    map<pii , int> magic;
    while(Q--){
        int x , y;
        cin >> x >> y;
        if(sp)swap(x , y);
        magic[{x , y}]++;
    }
    // forcing N >= M
    queue<pii> q;
    q.push({1 , 1});
    int ans = 0;
    vector<int> max_at(M + 1);
    while(!q.empty()){
        vector<pii> tmp;
        while(!q.empty()){
            pii cur = q.front();
            q.pop();
            int i = cur.x , j = cur.y;
            if(i == N && j == M){
                cout << ans << endl;
                return 0;
            }
            tmp.push_back({min(N , i + j + magic[{i , j}]) , j});
            max_at[j] = max(max_at[j] , min(N , i + j + magic[{i , j}]));
            tmp.push_back({i , min(M , i + j + magic[{i , j}])});
            max_at[min(M , i + j + magic[{i , j}])] = max(max_at[min(M , i + j + magic[{i , j}])] , i);
        }
        for(const auto& e : tmp){
            if(e.x >= max_at[e.y]){
                q.push({e.x , e.y});
            }
        }   
        ++ans;
    }
    cout << -1 << endl;
}