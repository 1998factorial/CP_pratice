#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<array<int , 2>> g[maxn];
int N;
vector<ll> vals;

void DFS(int v , int p , ll w){
    for(auto e : g[v]){
        int nv = e[0] , nw = e[1];
        if(nv != p){
            DFS(nv , v , w + nw);
        }
    }
    if(v != 1 && g[v].size() == 1){
        vals.push_back(w);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    ll ret = 0;
    for(int i = 1; i < N; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        ret += 2ll * w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    DFS(1 , 1 , 0);
    if(vals.empty()){
        cout << 0 << endl;
    }
    else if(vals.size() == 1){
        cout << vals.back() << endl;
    }
    else{
        ll mx = 0;
        for(auto i : vals)mx = max(mx , i);
        cout << ret - mx << endl;
    }
}