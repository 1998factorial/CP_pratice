#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(false)
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
int N , K , L , M , a[105];
bool mark[10005];
vector<int> pos;
int dis[25][25];
map<int , int> id;
vector<int> g[10005];
int dp[(1 << 22) + 1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K >> L;
    for(int i = 1; i <= K; ++i){
        int x;
        cin >> x;
        mark[x] = true;
    }
    for(int i = 0; i <= N; ++i){
        if(mark[i] != mark[i + 1]){
            pos.push_back(i);
            debug cout << i << endl;
        }
    }
    M = pos.size();
    for(int i = 0; i < M; ++i){
        id[pos[i]] = i;
    }
    for(int i = 1; i <= L; ++i){
        cin >> a[i];
        for(int j = 0; j + a[i] <= N; ++j){
            g[j].push_back(j + a[i]);
            g[j + a[i]].push_back(j);
        }
    }
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < M; ++j){
            if(i != j){
                dis[i][j] = inf32;
            }
        }
    }
    for(int i = 0; i < M; ++i){
        queue<int> q;
        vector<int> d(N + 10 , inf32);
        q.push(pos[i]);
        d[pos[i]] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int nv : g[v]){
                if(d[nv] < inf32)continue;
                d[nv] = d[v] + 1;
                if(id.find(nv) != id.end()){
                    dis[i][id[nv]] = d[nv];
                }
                q.push(nv);
            }
        }
    }
    debug{
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < M; ++j){
                cout << dis[i][j] << " ";
            }
            cout <<  endl;
        }
    }
    for(int mask = 0; mask < 1 << M; ++mask){
        dp[mask] = inf32;
    }
    dp[0] = 0;
    for(int mask = 1; mask < 1 << M; ++mask){
        for(int i = 0; i < M; ++i){
            if((mask >> i & 1) == 0)continue;
            for(int j = 0; j < M; ++j){
                if((mask >> j & 1) == 0)continue;
                if(i == j)continue;
                dp[mask] = min(dp[mask] , dp[mask ^ (1 << i) ^ (1 << j)] + dis[i][j]);
            }
        }
        debug printf("dp[%d] = %d\n" , mask , dp[mask]);
    }
    if(dp[(1 << M) - 1] < inf32){
        cout << dp[(1 << M) - 1] << endl;
    }
    else{
        cout << -1 << endl;
    }
} 