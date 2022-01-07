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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    f[0] = 1;
    inv[0] = qpow(f[0] , mod - 2);
    for(int i = 1; i < maxn; ++i){
        f[i] = mul(f[i - 1] , i);
        inv[i] = qpow(f[i] , mod - 2);
    }
    t = 1;
    while(t--){
        int N;
        cin >> N;
        vector<vector<int>> cnt(2 , vector<int>(3 , 0));
        vector<string> a;
        for(int i = 0; i < N; ++i){
            string s;
            cin >> s;
            a.push_back(s);
            for(int j = 0; j < 2; ++j){
                if(s[j] == 'W')++cnt[j][0];
                if(s[j] == 'B')++cnt[j][1];
                if(s[j] == '?')++cnt[j][2];
            }
        }
        // #[|0]=#[1|]
        // #[|1]=#[0|]
        // means, #(0)=#(1) and #[0|0]=#[1|1]
        // also, we can not have only (#[0|1]>=1 && #[1|0]>=1 && #[0|0]=#[1|1]=0)
        int nw = cnt[0][0] + cnt[1][0];
        int nb = cnt[0][1] + cnt[1][1];
        if(nw > N || nb > N){
            cout << 0 << endl;
            continue;
        }
        ll ans = C(2 * N - nw - nb , N - nw);
        // forcing #(0)=#(1) is enough for forcing #[0|0]=#[1|1]
        // we need to subtract the case where there is only [0|1] and [1|0]
        // but if all are [0|1], it is ok
        // if all are [1|0], also ok
        // so we need to add these back
        DEBUG(ans);
        DEBUG(nw);
        DEBUG(nb);
        ll bad = 1;
        for(string s : a){
            if(s[0] == s[1] && s[0] != '?'){
                bad = 0;
                break;
            }
            ll v = 0;
            if(s[0] == '?')++v;
            if(s[1] == '?')++v;
            if(v == 0)continue;
            bad = mul(bad , v);
        }
        DEBUG(bad);
        ans = add(ans , -bad);
        ll good = 1;
        // [0|1]
        for(string s : a){
            if(s[0] == s[1] && s[0] != '?'){
                good = 0;
                break;
            }
            if(s[0] == 'B' || s[1] == 'W'){
                good = 0;
                break;
            }
        }
        ans = add(ans , good);
        good = 1;
        for(string s : a){
            if(s[0] == s[1] && s[0] != '?'){
                good = 0;
                break;
            }
            if(s[0] == 'W' || s[1] == 'B'){
                good = 0;
                break;
            }
        }
        ans = add(ans , good);
        cout << ans << endl;
    }
}