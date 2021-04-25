#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 10;
const int inf = 1e9 + 100;
vector<int> g[maxn];
int N , M , tot , ctot , c[maxn] , dfn[maxn] , low[maxn] , cmpid[maxn];
bool instack[maxn];
int min_cost[maxn] , num[maxn];
vector<int> s;

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
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> c[i];
    cin >> M;
    for(int i = 1; i <= M; ++i){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    tot = 0;
    ctot = 0;
    for(int i = 1; i <= N; ++i){
        if(dfn[i] == 0){
            tarjan(i);
        }
    }
    for(int i = 1; i <= ctot; ++i){
        min_cost[i] = inf;
    }
    for(int i = 1; i <= N; ++i){
        min_cost[cmpid[i]] = min(min_cost[cmpid[i]] , c[i]);
    }
    ll ans1 = 0 , ans2 = 1;
    for(int i = 1; i <= ctot; ++i){
        ans1 += min_cost[i];
    }
    for(int i = 1; i <= N; ++i){
        if(c[i] == min_cost[cmpid[i]]){
            ++num[cmpid[i]];
        }
    }
    for(int i = 1; i <= ctot; ++i){
        ans2 = ans2 * num[i] % mod;
    }
    cout << ans1 << " " << ans2 << endl;
}