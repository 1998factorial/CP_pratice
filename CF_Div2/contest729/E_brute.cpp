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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
ll mod = 1e9 + 7;
int cnt[100][10000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N >> mod;
    vector<int> p(N) , q(N);
    for(int i = 0; i < N; ++i){
        p[i] = i;
        q[i] = i;
    }
    int ans = 0;
    do{
        int v = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(p[i] > p[j])++v;
            }
        }
        do{
            int u = 0;
            for(int i = 0; i < N; ++i){
                for(int j = i + 1; j < N; ++j){
                    if(q[i] > q[j])++u;
                }
            }
            if(p < q && v > u){
                for(int i : p)cout << i << " ";
                cout << endl;
                for(int i : q)cout << i << " ";
                cout << endl;
                ans++;
            }
        }while(next_permutation(q.begin() , q.end()));
    }while(next_permutation(p.begin() , p.end()));
    cout << ans << endl;
}