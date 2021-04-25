#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int N , M , dp[maxn] , ndp[maxn];
vector<array<int , 2>> edges[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        int u , v , w;
        cin >> u >> v >> w;
        edges[w].push_back({u , v});
    }
    for(int w = 0; w < maxn; ++w){
        if(edges[w].empty())continue;
        for(auto& e : edges[w]){
            int v = e[0] , nv = e[1];
            ndp[nv] = 0;
        }
        for(auto& e : edges[w]){
            int v = e[0] , nv = e[1];
            ndp[nv] = max(ndp[nv] , dp[v] + 1);
        }
        for(auto& e : edges[w]){
            int v = e[0] , nv = e[1];
            dp[nv] = max(dp[nv] , ndp[nv]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i)ans = max(ans , dp[i]);
    cout << ans << endl;
}
