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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;

vector<int> undirected_eular_circuit(int n , int m , const vector<vector<pii>>& G){
    for(auto& E : G)if(E.size() & 1)return {}; // odd degree
    vector<vector<pii>::const_iterator> it(n);
    for(int i = 0; i < n; ++i)it[i] = G[i].begin();
    vector<int> ans;
    vector<bool> done(n) , vis(m + 1);
    function<void(int)> dfs = [&](int v){
        done[v] = true;
        for(auto& cur = it[v]; cur != G[v].end();){
            int nv = cur->x , eid = cur->y;
            if(!vis[abs(eid)]){
                vis[abs(eid)] = true;
                dfs(nv);
                ans.push_back(eid);
            }
            else cur = next(cur);
        }
    };
    for(int i = 0; i < n; ++i)if(!G[i].empty() && !done[i])dfs(i);
    assert(ans.size() == m);
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    int t;
    t = 1;
    while(t--){
        int N , M;
        cin >> N >> M;
        vector<int> deg(2 * N + 2) , sum(N + 1);
        vector<pii> edges;
        for(int i = 0; i < M; ++i){
            int u , v , w;
            cin >> u >> v >> w;
            if(w == 1)edges.push_back({u , v});
            else edges.push_back({u + N , v + N});
            sum[u] += w;
            sum[v] += w;
        }
        for(auto& e : edges){
            ++deg[e.x];
            ++deg[e.y];
        }
        for(int i = 1; i <= N; ++i){
            if((deg[i] & 1) != (deg[i + N] & 1)){
                if(deg[i] & 1)edges.push_back({2 * N + 1 , i});
                else edges.push_back({2 * N + 1 , i + N});
            }   
            else if(deg[i] & 1){
                edges.push_back({i , i + N});
            }
        }
        vector<vector<pii>> G(2 * N + 2);
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i].x , v = edges[i].y;
            G[u].push_back({v , i + 1});
            G[v].push_back({u , -(i + 1)});
        }
        int ans = 0;
        for(int i = 1; i <= N; ++i)if(sum[i] & 1)++ans;
        cout << ans << endl;
        auto ret = undirected_eular_circuit(2 * N + 2 , (int)edges.size() , G);
        debug{
            for(int i : ret){
                if(i > 0){
                    printf("edges[%d] = (%d %d)\n" , i , edges[abs(i) - 1].x , edges[abs(i) - 1].y);
                }
                else{
                    printf("edges[%d] = (%d %d)\n" , i , edges[abs(i) - 1].y , edges[abs(i) - 1].x);
                }
            }
            for(int i : ret)cout << i << ' ';
            cout << endl;
        }
        vector<int> dir(M + 1);
        for(int i : ret){
            if(abs(i) <= M){
                dir[abs(i)] = 1 + (i < 0);
            }
        }
        for(int i = 1; i <= M; ++i)cout << dir[i];
        cout << endl;
    }
}