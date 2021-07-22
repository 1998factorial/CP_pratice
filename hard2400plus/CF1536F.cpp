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
const int maxn = 1e6 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 1e9 + 7;
/*
    Bob can force wins for all N >= 2
    as long as we have #(A) = #(B)
    so, every valid game state counts
    valid game state looks like AB_ABA_BA_B_
*/
ll f[maxn];
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    return (x + y) % mod;
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
    return mul(f[n] , mul(inverse(f[n - m]) , inverse(f[m])));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    f[0] = 1;
    for(int i = 1; i < maxn; ++i)f[i] = mul(f[i - 1] , i);
    ll ans = 0;
    for(int k = 0; k <= N; k += 2){
        if(N / 2 + (N % 2) <= k && k <= N){
            ll v = mul(2ll , f[k]);
            if(k == N){
                ans = add(ans , v);
            }
            else{
                v = mul(v , add(C(k , N - k) , C(k - 1 , N - k - 1)));
                ans = add(ans , v);
            }
        }
    }
    cout << ans << endl;
}