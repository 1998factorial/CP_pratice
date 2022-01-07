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
const ll mod = 1e9 + 7;
ll add(ll x , ll y){
    return ((x + y) % mod + mod) % mod;
}
ll mul(ll x , ll y){
    return x * y % mod;
}
ll qpow(ll x , ll n){
    ll ret = 1ll;
    while(n){
        if(n % 2)ret = mul(ret , x);
        x = mul(x , x);
        n >>= 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        ll ans = add(qpow(2ll , N) , -1);
        vector<int> cnt(31);
        for(int i : a){
            int v = i , c = 0;
            while(v % 2 == 0){
                v /= 2;
                ++c;
            }
            ++cnt[c];
        }
        int num = cnt[0];
        for(int i = 1; i <= 30; ++i){
            // fix the smallest power of 2, which is 2^i
            // when is a sequence bad? when the lowest such power 
            // appears odd times
            if(cnt[i] == 0)continue;
            num += cnt[i];
            ll val = qpow(2ll , N - num + cnt[i] - 1);
            ans = add(ans , -val);
        }
        cout << ans << endl;
    }
}