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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int add(ll x , ll y){
    x %= mod;
    y %= mod;
    ll ans = (x + y) % mod;
    return ans;
}
int mul(ll x , ll y){
    x %= mod;
    y %= mod;
    ll ans = ((ll)x * y) % mod;
    return ans;
}
int sub(ll x , ll y){
    x %= mod;
    y %= mod;
    ll ans = ((ll)x - y) % mod;
    return (ans + mod) % mod;
}
const int base = maxv;
ll cnt[maxv * 2 + 10];
ll fac[maxv];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // first part of the problem is to calculate the maximal score
    // second part of the problem is to count the number of permutations
    // on a that can achieve maximal score
    fac[0] = 1;
    for(int i = 1; i < maxv; ++i)fac[i] = mul(fac[i - 1] , i);
    int M;
    cin >> M;
    vector<int> c(M);
    int mx = 0;
    for(int i = 0; i < M; ++i){
        cin >> c[i];
        mx = max(mx , c[i]);
        int l = base + 1 - c[i];
        int r = base + c[i] - 1;
        ++cnt[l];
        --cnt[r + 2];
    }
    ll max_score = 0 , nways = 1 , num = 0;
    for(int v = -mx - 1; v <= mx + 1; ++v){
        int x = base + v;
        cnt[x] += cnt[x - 2];
        nways = mul(nways , fac[cnt[x]]);
        ll val = mul(cnt[x] , num);
        val = add(val , (ll)cnt[x] * (cnt[x] + 1) / 2);
        val = mul(val , v);
        max_score = add(max_score , val);
        num = add(num , cnt[x]);
    }
    cout << max_score << " " << nways << endl; 
}