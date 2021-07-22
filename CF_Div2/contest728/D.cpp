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
const int maxn = 255;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 1e9 + 7;
ll f[maxn];
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    x += y;
    if(x >= mod)x -= mod;
    return x;
}
ll sub(ll x , ll y){
    x -= y;
    if(x < 0)x += mod;
    return x;
}
ll qpow(ll x , ll n){
    ll ans = 1;
    while(n){
        if(n & 1)ans = mul(ans , x);
        x = mul(x , x);
        n /= 2;
    }
    return ans;
}
ll inverse(ll x){
    return qpow(x , mod - 2);
}
ll C(int n , int m){
    if(n < 0 || m < 0 || n < m)return 0;
    return mul(f[n] , mul(inverse(f[n - m]) , inverse(f[m])));
}
int N;
vector<int> g[maxn];
ll dpL[maxn][maxn];
int tin[maxn] , tout[maxn] , height[maxn] , tot , L , up[maxn][20];
void DFS(int v , int p , int h){
    height[v] = h;
    tin[v] = ++tot;
    up[v][0] = p;
    for(int i = 1; i <= L; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(int nv : g[v]){
        if(p != nv){
            DFS(nv , v , h + 1);
        }
    }
    tout[v] = tot;
}
bool isAncestor(int v , int u){ //check if v is ancestor of u
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}
int find_lca(int v , int u){
    for(int i = L; i >= 0; --i){
        if(!isAncestor(up[v][i] , u)){
            v = up[v][i];
        }
    }
    return up[v][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i < N; ++i){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    f[0] = 1;
    for(int i = 1; i < maxn; ++i){
        f[i] = mul(f[i - 1] , i);
    }
    for(int i = 1; i <= N; ++i){
        dpL[0][i] = 1;
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            dpL[i][j] = mul(inverse(2ll) , add(dpL[i - 1][j] , dpL[i][j - 1]));
        }
    }
    L = ceil(log2(N));
    ll ans = 0;
    for(int root = 1; root <= N; ++root){
        tot = 0;
        DFS(root , root , 0);
        for(int v = 1; v <= N; ++v){
            for(int u = 1; u < v; ++u){
                if(isAncestor(u , v))continue;
                int lca = find_lca(u , v);
                int disv = height[v] - height[lca];
                int disu = height[u] - height[lca];
                ans = add(ans , dpL[disv][disu]);
            }
        }
    }
    cout << mul(ans , inverse(N)) << endl;
}