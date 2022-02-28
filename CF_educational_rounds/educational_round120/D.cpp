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
const int mod = 998244353;
char a[5005];
int f[5005] , inv[5005];
ll add(ll x , ll y){
    ll ans = (x + y) % mod;
    return ans;
}
ll mul(ll x , ll y){
    int ans = x * y % mod;
    return ans;
}
ll qpow(ll x , ll n){
    ll ret = 1ll;
    while(n){
        if(n % 2)ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}
ll C(int n , int r){
    if(n < r || n < 0 || r < 0)return 0;
    return mul(f[n] , mul(inv[n - r] , inv[r]));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , K;
    cin >> N >> K;
    f[0] = 1;
    inv[0] = qpow(f[0] , mod - 2);
    for(int i = 1; i <= N; ++i){    
        f[i] = mul(f[i - 1] , i);
        inv[i] = qpow(f[i] , mod - 2);
    }
    cin >> (a + 1);
    int nones = 0;
    for(int i = 1; i <= N; ++i)if(a[i] == '1')++nones;
    if(K == 0 || K > nones){
        cout << 1 << endl;
        return 0;
    }
    int ans = 1;
    for(int i = 1; i <= N; ++i){
        int ones = a[i] == '1';
        for(int j = i + 1; j <= N; ++j){
            ones += a[j] == '1';
            if(ones > K){
                break;
            }
            ans = add(ans , C((j - 1) - (i + 1) + 1 , ones - (a[i] == '0') - (a[j] == '0')));
        }
    }
    cout << ans << endl;
}