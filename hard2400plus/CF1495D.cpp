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
const ll mod = 998244353;
int N , M , dis[405][405];
vector<int> g[405];
ll mul(ll x , ll y){
    return x * y % mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            dis[i][j] = (i == j) ? 1 : inf32;
        }
    }
    for(int i = 1; i <= M; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        dis[u][v] = min(dis[u][v] , 2);
        dis[v][u] = min(dis[v][u] , 2);
    }
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j] - 1);
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            // if there are not only one shortest path between i and j
            // then we have 0 BFS-spanning tree sourcing at i and j
            int num_on_path = 0;
            for(int k = 1; k <= N; ++k){
                if(dis[i][k] + dis[k][j] - 1 == dis[i][j]){
                    ++num_on_path;
                }
            }
            if(num_on_path > dis[i][j]){
                cout << 0 << " ";
                continue;
            }
            // now, path between i and j is fixed and must be unique
            // for each vertex k that is not on path(i , j)
            // we count the number of edges from this k (layer l) to layer l - 1
            // answer is the product of all these numbers
            ll ans = 1; 
            for(int k = 1; k <= N; ++k){
                if(dis[i][k] + dis[k][j] - 1 == dis[i][j])continue;
                ll nchoices = 0;
                for(int v : g[k]){
                    if(dis[i][k] - 1 == dis[i][v] && dis[j][k] - 1 == dis[j][v]){
                        ++nchoices;
                    }
                }
                ans = mul(ans , nchoices);
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}           
