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
int N , K , L , len[105] , a[10005] , c[10005] , dis[35][35] , dp[(1 << 20) + 5];
vector<int> g[10005] , ones;
map<int , int> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K >> L;
    for(int i = 1; i <= K; ++i){
        int x;
        cin >> x;
        ++a[x];
    }
    // construct c
    for(int i = 0; i <= N; ++i){
        if(a[i] != a[i + 1]){
            c[i] = 1;
            ones.push_back(i);
            mp[i] = ones.size() - 1;
        }
    }
    // flip [L,R] , alter c[L-1] , C[R]
    for(int j = 1; j <= L; ++j){
        cin >> len[j];
        for(int i = 0; i + len[j] <= N; ++i){
            g[i].push_back(i + len[j]);
            g[i + len[j]].push_back(i);
        }
    }
    int M = ones.size();
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < M; ++j){
            if(i != j)dis[i][j] = inf32;
        }
    }
    for(int i : ones){
        int id = mp[i];
        vector<int> d(N + 10 , inf32);
        queue<int> q;
        q.push(i);
        d[i] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int nv : g[v]){
                if(d[nv] > d[v] + 1){
                    d[nv] = d[v] + 1;
                    q.push(nv);
                    if(mp.find(nv) != mp.end()){
                        dis[id][mp[nv]] = min(dis[id][mp[nv]] , d[nv]);
                    }
                }
            }
        }
    }
    for(int mask = 1; mask < 1 << M; ++mask)dp[mask] = inf32;
    for(int mask = 1; mask < 1 << M; ++mask){
        for(int i = 0; i < M; ++i){
            if(mask >> i & 1){
                for(int j = i + 1; j < M; ++j){
                    if(mask >> j & 1){
                        dp[mask] = min(dp[mask] , dp[mask ^ (1 << i) ^ (1 << j)] + dis[i][j]);
                    }
                }
            }
        }
    }
    int ans = (dp[(1 << M) - 1] < inf32) ? dp[(1 << M) - 1] : -1;
    cout << ans << endl;
}