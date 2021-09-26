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
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N;
int a[maxn];
ll f[maxn];
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll mul(ll x , ll y){
    return x * y % mod;
}
ll qpow(ll x , ll n){
    if(n <= 0)return 1;
    ll ans = qpow(x , n / 2);
    ans = mul(ans , ans);
    if(n & 1)ans = mul(ans , x);
    return ans;
}
ll inv(ll x){
    return qpow(x , mod - 2);
}
ll C(ll n , ll m){
    if(n < m || n < 0 || m < 0)return 0;
    return mul(f[n] , mul(inv(f[n - m]) , inv(f[m])));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll sum = 0;
    cin >> N;
    f[0] = 1;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        sum += a[i];
        f[i] = mul(f[i - 1] , (ll)i);
    }
    if(sum % N != 0){
        cout << 0 << endl;
    }
    else{
        ll t = sum / N;
        int L = 0 , R = 0 , M = 0;
        map<int , int> freq;
        for(int i = 1; i <= N; ++i){
            ++freq[a[i]];
            if(a[i] < t)++L;
            if(a[i] == t)++M;
            if(a[i] > t)++R;
        }
        if(M == N || L == 1 || R == 1){
            ll ans = f[N];
            for(auto e : freq){
                ans = mul(ans , inv(f[e.y]));
            }
            cout << ans << endl;
        }
        else{
            ll ans = 0;
            // all L before R
            for(int i = L; R <= N - i; ++i){
                ll v = 0;
                v = add(v , C(i - 1 , L - 1));
                v = mul(v , C(N - i , R));
                ans = add(ans , v);
            }
            // all R before L
            for(int i = R; L <= N - i; ++i){
                ll v = 0;
                v = add(v , C(i - 1 , R - 1));
                v = mul(v , C(N - i , L));
                ans = add(ans , v);
            }
            ans = mul(f[L] , ans);
            ans = mul(f[R] , ans);
            ans = mul(f[M] , ans);
            for(auto e : freq){
                ans = mul(ans , inv(f[e.y]));
            }
            /*ans = 0;
            ans = C(N , M);
            ans = mul(ans , 2ll);
            ans = mul(ans , f[L]);
            ans = mul(ans , f[R]);
            ans = mul(ans , f[M]);
            for(auto e : freq){
                ans = mul(ans , inv(f[e.y]));
            }*/
            cout << ans << endl;
        }
    }
} 
