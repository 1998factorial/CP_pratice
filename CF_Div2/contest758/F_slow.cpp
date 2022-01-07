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
const ll mod = 998244353;
ll f[maxn] , inv[maxn];
ll add(ll x , ll y){
    return ((x + y) % mod + mod) % mod; 
}
ll mul(ll x , ll y){
    return (x * y) % mod;
}
inline ll qpow(ll x , ll n){
    ll ret = 1ll;
    while(n){
        if(n % 2)ret = mul(ret , x);
        x = mul(x , x);
        n >>= 1;
    }
    return ret;
}
ll C(int n , int r){
    if(n < 0 || r < 0 || n < r)return 0;
    return mul(f[n] , mul(inv[n - r] , inv[r]));
}
int b[2005] , L[2005] , R[2005];
ll dp[2][2005][2005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , K;
    cin >> N >> K;
    f[0] = 1;
    inv[0] = qpow(f[0] , mod - 2);
    for(int i = 1; i < maxn; ++i){
        f[i] = mul(f[i - 1] , i);
        inv[i] = qpow(f[i] , mod - 2);
    }
    for(int i = 1; i <= N; ++i){
        cin >> b[i];
    }
    for(int i = 0; i <= N; ++i){
        L[i] = max(0 , b[i] - K);
        R[i] = min(b[i] + K , i);
    }
    // dp[i][k][j] , (first i , mex = k , # > mex is j)
    dp[0][0][0] = 1;
    for(int i = 0; i < N; ++i){ 
        memset(dp[1] , 0 , sizeof(dp[1]));
        for(int j = 0; j <= i; ++j){ // # distinct value > mex
            for(int k = L[i]; k <= R[i]; ++k){ // mex
                if(dp[0][k][j] == 0)continue;
                if(L[i + 1] <= k && k <= R[i + 1]){
                    dp[1][k][j] = add(dp[1][k][j] , mul(dp[0][k][j] , j + k));
                    dp[1][k][j + 1] = add(dp[1][k][j + 1] , dp[0][k][j]);
                }
                for(int nk = L[i + 1]; nk <= R[i + 1]; ++nk){
                    int choose = nk - k - 1;
                    if(choose < 0 || j - choose < 0)continue;
                    ll val = mul(f[j] , inv[j - choose]);
                    val = mul(val , dp[0][k][j]);
                    // dp[nk][j - choose] += dp[k][j] * (j)! / (j - choose)!
                    dp[1][nk][j - choose] = add(dp[1][nk][j - choose] , val);
                }
            }
        }
        swap(dp[0] , dp[1]);
    }
    ll ans = 0;
    for(int k = L[N]; k <= R[N]; ++k){
        for(int j = 0; j <= N; ++j){
            if(N - k - j < 0)continue;
            ll v = mul(f[N - k] , inv[N - k - j]);
            ans = add(ans , mul(v , dp[0][k][j]));
        }
    }
    cout << ans << endl;
}