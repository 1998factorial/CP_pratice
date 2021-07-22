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
const int maxn = 4e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , M;
vector<int> g[maxn];
int ans[maxn] , vis[maxn];
void DFS(int v , int p , int ){
    for(int nv : g[v]){
        if(){

        }
    }
}
vector<int> s;
bool instack[maxn];
int dfn[maxn] , low[maxn] , tot , cmpid[maxn];
void tarjan(int v){
    s.push_back(v);
    instack[v] = true;
    dfn[v] = low[v] = ++tot;
    for(int nv : g[v]){
        if(!dfn[nv]){
            tarjan(nv);
            low[v] = min(low[v] , low[nv]);
        }
        else if(instack[nv]){
            low[v] = min(low[v] , dfn[nv]);
        }
    }
    if(low[v] == dfn[v]){
        ++ctot;
        for(;;){
            int t = s.back();
            s.pop_back();
            instack[t] = false;
            cmpid[t] = ctot;
            if(t == v)break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> N >> M;
        tot = 0;
        for(int i = 1; i <= N; ++i)g[i].clear() , ans[i] = -2 , vis[maxn];
        for(int i = 1; i <= N; ++i){
            cmpid[i] = 0;
            instack[i] = false;
            dfn[i] = 0;
            low[i] = 0;
        }
        for(int i = 1; i <= M; ++i){
            int u , v;
            cin >> u >> v;
            if(u == v){
                ans[u] = -1;
            }
            if(u != v)g[u].push_back(v);
        }
        tarjan(1);
        int smallest_neg = N + 1;
        for(int i = 1; i <= N; ++i){
            if(ans[i] == -1){
                smallest_neg = min(smallest_neg , dfn[i]);
            }
        }
        for(int i = 1; i <= N; ++i){
            if(dfn[i] <= smallest_neg){
                ans[i] = -1;
            }
        }
        for(int i = 1; i <= N; ++i){
            if(!dfn[i])ans[i] = 0;
        }
        for(int i = 1; i <= N; ++i)cout << ans[i] << " ";
        cout << endl;
    }
}  