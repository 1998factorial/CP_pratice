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
const int maxn = 3e5 + 10;
const int maxq = 5e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , Q , tin[maxn] , tout[maxn] , total , up[maxn][25] , LOG[maxn] , xor_from_root[maxn];
vector<pii> g[maxn];
array<int , 3> edges[maxq];
int ans[maxq];
struct DSU{
    int fa[maxn];
    void init(int n){
        for(int i = 1; i <= n; ++i){
            fa[i] = i;
        }
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unite(int x , int y){
        x = find(x);
        y = find(y);
        if(x != y){
            fa[x] = y;
        }
    }
} D;
struct fenwick{
    int sum[maxn * 4];
    void init(){
        memset(sum , 0 , sizeof(sum));
    }
    int query(int pos){
        int ans = 0;
        while(pos){
            ans += sum[pos];
            pos -= pos & (-pos);
        }
        return ans;
    }
    void add(int pos , int val){
        while(pos <= N + 10){
            sum[pos] += val;
            pos += pos & (-pos);
        }
    }
} T;
void DFS(int v , int p , int xorv){
    tin[v] = ++total;
    up[v][0] = p;
    xor_from_root[v] = xorv;
    for(int i = 1; i <= LOG[N]; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(auto& e : g[v]){
        int nv = e.x , w = e.y;
        if(nv != p){
            DFS(nv , v , xorv ^ w);
        }
    }
    tout[v] = total;
}
bool is_ancestor(int u , int v){ // check if u is ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u , int v){ // return the LCA of u and v
    if(is_ancestor(u, v)) 
        return u;
    if(is_ancestor(v, u))
        return v;
    for(int i = LOG[N]; i >= 0; --i){
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    D.init(N);
    T.init();
    total = 0;
    for(int i = 2; i < maxn; ++i){
        LOG[i] = LOG[i / 2] + 1;
    }
    for(int i = 1; i <= Q; ++i){
        ans[i] = -1;
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    for(int i = 1; i <= Q; ++i){
        int u = edges[i][0] , v = edges[i][1] , w = edges[i][2];
        if(D.find(u) != D.find(v)){
            D.unite(u , v);
            ans[i] = 1;
            g[u].push_back({v , w});
            g[v].push_back({u , w});
        }
    }
    for(int i = 1; i <= N; ++i){
        if(tin[i] == 0){
            DFS(i , i , 0);
        }
    }
    for(int i = 1; i <= Q; ++i){
        if(~ans[i])continue;
        ans[i] = 0;
        // must be cycle edge
        int u = edges[i][0] , v = edges[i][1] , w = edges[i][2];
        int lca_uv = lca(u , v);
        // check if the path from u to v is unique
        int S = T.query(tin[u]) + T.query(tin[v]) - 2 * T.query(tin[lca_uv]);
        if(S > 0){
            continue;
        }
        // check xor sum from u to v
        int val = xor_from_root[u] ^ xor_from_root[v] ^ w;
        if(val != 1){
            continue;
        }
        ans[i] = 1;
        // mark the path from u to v as not unique
        while(u != lca_uv){
            T.add(tin[u] , 1);
            T.add(tout[u] + 1 , -1);
            u = up[u][0];
        }
        while(v != lca_uv){
            T.add(tin[v] , 1);
            T.add(tout[v] + 1 , -1);
            v = up[v][0];
        }
    }
    for(int i = 1; i <= Q; ++i){
        if(ans[i] == 1){
            cout << "YES" << endl;
        }
        else if(ans[i] == 0){
            cout << "NO" << endl;
        }
    }
}   
