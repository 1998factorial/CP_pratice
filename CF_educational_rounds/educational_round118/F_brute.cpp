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
const int maxv = 2e6 + 10;
const int maxn = 250010;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
vector<int> g[maxn];
int nc[maxn] , dp[5005][5005] , f[maxn];
int N;
ll add(ll x , ll y){
    return ((x + y) % mod + mod) % mod;
}
ll mul(ll x , ll y){
    return x * y % mod;
}
void DFS(int v , int p){
    for(int nv : g[v]){
        if(nv == p)continue;
        DFS(nv , v);
        ++nc[v];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    f[0] = 1;
    for(int i = 1; i <= N; ++i)f[i] = mul(f[i - 1] , i);
    for(int i = 2; i <= N; ++i){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1 , 1);
    for(int j = 0; j <= N; ++j)dp[j][0] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j){
            dp[i][j] = add(dp[i][j] , dp[i - 1][j]);
            dp[i][j] = add(dp[i][j] , mul(dp[i - 1][j - 1] , nc[i]));
        }
    }
    ll ans = 0;
    for(int k = 0; k <= N - 1; ++k){
        ll sign = 1;
        if(k & 1)sign = -1;
        ll val = mul(sign , dp[N][k]);
        val = mul(val , f[N - k]);
        ans = add(ans , val);
    }
    cout << ans << endl;
}
