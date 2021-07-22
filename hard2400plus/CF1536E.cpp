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
char a[2005][2005];
ll f[maxn];
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
ll C(int n , int m){
    if(n < 0 || m < 0 || n < m)return 0;
    return mul(f[n] , mul(inverse(f[n - m]) , inverse(f[m])));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , M;
        cin >> N >> M;
        for(int i = 1; i <= N; ++i){
            cin >> (a[i] + 1);
        }
        int cnt = 0;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                if(a[i][j] == '#'){
                    ++cnt;
                }
            }
        }
        ll ans = qpow(2ll , cnt);
        if(cnt == N * M)ans = sub(ans , 1ll);
        cout << ans << endl;
    }
}