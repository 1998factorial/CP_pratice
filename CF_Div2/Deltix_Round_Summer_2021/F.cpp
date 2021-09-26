#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll sub(ll x , ll y){
    return ((x - y) % mod + mod) % mod;
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
int N , a[14];
ll inv[maxv * 2] , g[14][1 << 14] , dp[1 << 14];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i)cin >> a[i];
    for(int i = 1; i < maxv * 2; ++i)inv[i] = inverse(i);
    for(int i = 0; i < N; ++i){
        for(int mask = 0; mask < 1 << N; ++mask){
            if(mask >> i & 1)continue;
            g[i][mask] = 1;
            for(int j = 0; j < N; ++j){
                if(mask >> j & 1){
                    g[i][mask] = mul(g[i][mask] , mul(a[i] , inv[a[i] + a[j]]));
                }
            }
        }
    }
    for(int mask = 1; mask < 1 << N; ++mask){
        dp[mask] = 1;
        for(int submask = mask - 1; submask > 0; submask = (submask - 1) & mask){
            ll v = 1;
            for(int i = 0; i < N; ++i){
                if(submask >> i & 1){
                    v = mul(v , g[i][mask ^ submask]);
                }
            }
            dp[mask] = sub(dp[mask] , mul(dp[submask] , v));
        }
    }
    ll ans = 0;
    for(int mask = 1; mask < 1 << N; ++mask){
        ll v = 1;
        for(int i = 0; i < N; ++i){
            if(mask >> i & 1){
                v = mul(v , g[i][((1 << N) - 1) ^ mask]);
            }
        }
        ans = add(ans , mul(mul(dp[mask] , v) , __builtin_popcount(mask)));
    }
    cout << ans << endl;
} 