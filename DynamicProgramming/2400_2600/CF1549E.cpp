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
const int maxv  = 1e6 + 10;
const int maxn = 1e6 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N , Q;
ll fac[maxn * 3] , inv[maxn * 3] , dp[maxn * 3][3];
int add(int x , int y){
    ll ans = x;
    ans += y;
    if(ans >= mod)ans -= mod;
    return ans;
}
int sub(int x , int y){
    ll ans = x - y;
    if(ans < 0)ans += mod;
    return ans;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
int qpow(ll x , ll n){
    if(n <= 0)return 1;
    ll ret = qpow(x , n / 2);
    ret = mul(ret , ret);
    if(n & 1)ret = mul(ret , x);
    return ret;
}
int inverse(ll x){
    return qpow(x , mod - 2);
}
int C(int n , int r){
    if(n < r || n < 0 || r < 0)return 0;
    return mul(fac[n] , mul(inv[n - r] , inv[r]));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    fac[0] = 1;
    for(int i = 1; i <= 3 * N; ++i){
        fac[i] = mul(fac[i - 1] , i);
    }
    inv[3 * N] = inverse(fac[3 * N]);
    for(int i = 3 * N - 1; i >= 0; --i){
        inv[i] = mul(inv[i + 1] , i + 1);
    }
    dp[0][0] = dp[0][1] = dp[0][2] = N;
    int three_inv = inverse(3);
    for(int i = 1; i <= 3 * N; ++i){
        //dp[i][0] = sub(C(3 * N , i + 1) , add(dp[i][1] , dp[i][2]));
        dp[i][0] = mul(sub(C(3 * N , i + 1) , add(mul(2 , dp[i - 1][0]) , dp[i - 1][1])) , three_inv);
        dp[i][1] = add(dp[i - 1][0] , dp[i][0]);
        dp[i][2] = add(dp[i - 1][1] , dp[i][1]);
    }
    while(Q--){
        int x;
        cin >> x;
        cout << add(dp[x][0] , C(3 * N , x)) << endl;
    }
} 