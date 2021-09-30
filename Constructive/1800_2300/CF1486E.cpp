#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N , M;
ll dis[maxn][2][105];
bool vis[maxn][2][105];
vector<pii> g[maxn];
void solve(int src){
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k <= 100; ++k){
                dis[i][j][k] = inf64;
                vis[i][j][k] = false;
            }
        }
    }
    dis[1][0][0] = 0;
    priority_queue<array<ll , 4> , vector<array<ll , 4>> , greater<array<ll , 4>>> pq;
    pq.push({dis[1][0][0] , 1 , 0 , 0});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll d = cur[0] , v = cur[1] , p = cur[2] , w = cur[3];
        if(vis[v][p][w])continue;
        vis[v][p][w] = true;
        for(auto e : g[v]){
            int nv = e.x , nw = e.y , np = 1 ^ p;
            if(p == 0){
                if(vis[nv][np][nw + w])continue;
                if(dis[nv][np][nw + w] > d){
                    dis[nv][np][nw + w] = d;
                    pq.push({dis[nv][np][nw + w] , nv , np , nw + w});
                }
            }
            else{
                if(vis[nv][np][0])continue;
                if(dis[nv][np][0] > d + (nw + w) * (nw + w)){
                    dis[nv][np][0] = d + (nw + w) * (nw + w);
                    pq.push({dis[nv][np][0] , nv , np , 0});
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    solve(1);
    for(int i = 1; i <= N; ++i){
        if(dis[i][0][0] >= inf64)cout << -1 << " ";
        else cout << dis[i][0][0] << " ";
    }
    cout << endl;
} 