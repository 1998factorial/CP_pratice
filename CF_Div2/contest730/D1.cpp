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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
ll mod = 1e9 + 7;
ll fac[maxn];
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    x += y;
    if(x >= mod)x -= mod;
    return x;
}
ll sub(ll x , ll y){
    x -= y;
    if(x < 0)x += mod;
    return x;
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
ll C(int n , int m){
    if(n < 0 || m < 0 || n < m)return 0;
    return mul(fac[n] , mul(inverse(fac[n - m]) , inverse(fac[m])));
}
ll query(ll v){
    cout << v << endl;
    cout.flush();
    ll ans;
    cin >> ans; 
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    // 0
    // 0 ^ 1
    // 0 ^ 1 ^ 2
    // 0 ^ 1 ^ 2 ^ 3
    // guess i ^ (cancell out previous guesses)
    while(t--){
        int N , K;
        cin >> N >> K;
        int pre = 0;
        for(int i = 0; i <= N - 1; ++i){
            int ret = query(i ^ pre);
            if(ret)break;
            pre ^= pre ^ i;
        }
    }
}   