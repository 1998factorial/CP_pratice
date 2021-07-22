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
int N , M , ok , vis[maxn] , odd_cycle;
ll v[maxn] , t[maxn] , d[maxn];
vector<int> g[maxn];
void DFS(int u , int p){
    vis[u] = 1;
    for(int nv : g[u]){
        if(nv == p)continue;
        if(!vis[nv])DFS(nv , u);
        ll val = d[nv];
        d[nv] -= val;
        d[u] -= val;    
    }
}
void DFS2(int u , int p , int c){
    vis[u] = c;
    for(int nv : g[u]){
        if(vis[nv] == -1){
            DFS2(nv , u , c ^ 1);
        }
        if(vis[nv] == vis[u])odd_cycle = 1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 1; i <= N; ++i)vis[i] = 0;
        for(int i = 1; i <= N; ++i)g[i].clear();
        for(int i = 1; i <= N; ++i)cin >> v[i];
        for(int i = 1; i <= N; ++i)cin >> t[i];
        for(int i = 1; i <= N; ++i)d[i] = t[i] - v[i];
        for(int i = 1; i <= M; ++i){
            int u , v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // this accumulates all differences to vertex 1
        DFS(1 , 1);
        // check if there is a cycle of odd length
        ok = 0;
        odd_cycle = 0;
        for(int i = 1; i <= N; ++i)vis[i] = -1;
        DFS2(1 , 1 , 0);
        if(odd_cycle && d[1] % 2 == 0)ok = 1;
        if(d[1] == 0)ok = 1;
        if(ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}