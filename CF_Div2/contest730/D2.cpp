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
vector<int> to_basek(ll v , ll k){
    vector<int> ans;
    for(int i = 0; i <= 26; ++i){
        ans.push_back(v % k);
        v /= k;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
ll XOR(ll x , ll y , int k){
    vector<int> a = to_basek(x , k);
    vector<int> b = to_basek(y , k);
    ll ans = 0;
    for(int i = 0; i < a.size(); ++i){
        ans = ans * k;
        ans += (a[i] + b[i]) % k;
    }
    return ans;
}
ll INV(ll x , int k){
    vector<int> a = to_basek(x , k);
    ll ans = 0;
    for(int i = 0; i < a.size(); ++i){
        a[i] = (k - a[i]) % k;
        ans = ans * k;
        ans += a[i];
    }
    return ans;
}
void show(ll v , int k){
    auto r = to_basek(v , k);
    for(int i : r)cout << i;
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , K;
        cin >> N >> K;
        ll extra = 0;
        //password[i] = query[i] xork inverse(password[i - 1])
        //each password is a combination of extra part and initial password
        //each time we try ask if x is the initial password
        for(int i = 0; i <= N - 1; ++i){
            ll v = XOR(extra , (i % 2 == 0) ? i : INV(i , K) , K);
            int ret = query(v);
            if(ret)break;
            extra = XOR(v , INV(extra , K) , K);
        }
    }
}   