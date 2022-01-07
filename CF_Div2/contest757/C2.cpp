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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll qpow(ll x , ll n){
    if(n == 0)return 1ll;
    ll ret = qpow(x , n / 2);
    ret = mul(ret , ret);
    if(n & 1)ret = mul(ret , x);
    return ret;
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
        vector<int> a(30);
        for(int i = 1; i <= M; ++i){
            int l , r , v;
            cin >> l >> r >> v;
            for(int j = 0; j < 30; ++j){
                if(v >> j & 1)++a[j];
            }
        }
        ll ans = 0;
        for(int j = 0; j < 30; ++j){
            if(a[j]){
                ll ways = qpow(2ll , N - 1);
                ans = add(ans , mul(ways , 1ll << j));
            }
        }
        cout << ans << endl;
    }
}