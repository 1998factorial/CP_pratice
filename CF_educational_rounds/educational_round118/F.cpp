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
const int maxn = 250010;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
vector<int> g[maxn];
int nc[maxn] , f[maxn];
int N;
int add(ll x , ll y){
    return ((x + y) % mod + mod) % mod;
}
int mul(ll x , ll y){
    return x * y % mod;
}
void DFS(int v , int p){
    for(int nv : g[v]){
        if(nv == p)continue;
        DFS(nv , v);
        ++nc[v];
    }
}
namespace NTT {
    #define sz(a) a.size()
    typedef long long ll;
    const ll mod = 998244353;
    inline ll add(ll x , ll y){
        return (((long long)x + (long long)y) % mod + mod) % mod;
    }
    inline ll mul(ll x , ll y){
        return (long long)x * (long long)y % mod;
    }
    inline ll qpow(ll x , ll n){
        ll ret = 1ll;
        while(n){
            if(n % 2)ret = ret * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }
    vector<vector<ll>> poly;

    void change(vector<ll>& y , int len) {
        int i, j, k;
        for (i = 1, j = len / 2; i < len - 1; i++) {
            if (i < j) swap(y[i], y[j]);
            k = len / 2;
            while (j >= k) {
                j = j - k;
                k = k / 2;
            }
            if (j < k) j += k;
        }
    }

    void NTT(vector<ll>& P , int op){
        int len = sz(P) , i , j , k;
        change(P , len);
        for(i = 1; i < len; i <<= 1){
            ll gn = qpow(3ll , (mod - 1) / (i << 1));
            if(op == -1)gn = qpow(gn , mod - 2);
            for(j = 0; j < len; j += (i << 1)){
                ll g = 1;
                for(k = 0; k < i; ++k , g = g * gn % mod){
                    ll x = P[j + k] , y = g * P[j + k + i] % mod;
                    P[j + k] = (x + y) % mod;
                    P[j + k + i] = (x - y + mod) % mod;
                }
            }
        }
        if(op == -1){
            ll inv = qpow(len , mod - 2);
            for(i = 0; i < len; ++i)P[i] = P[i] * inv % mod;
        }
    }

    vector<ll> multiply(vector<ll> aa , vector<ll> bb){
        int n = sz(aa) , m = sz(bb) , len = 1 , i;
        while(len < n + m)len <<= 1;
        vector<ll> a(len) , b(len);
        for(i = 0; i < n; ++i)a[i] = aa[i];
        for(i = 0; i < m; ++i)b[i] = bb[i];
        NTT(a , 1);
        NTT(b , 1);
        vector<ll> c(len);
        for(i = 0; i < len; ++i)c[i] = a[i] * b[i] % mod;
        NTT(c , -1);
        while(!c.empty() && c.back() == 0)c.pop_back();
        return c;
    }

    vector<ll> solve(int l , int r){
        vector<ll> ret;
        priority_queue<pair<int , vector<ll>> , vector<pair<int , vector<ll>>> , greater<pair<int , vector<ll>>>> q;
        for(auto p : poly)q.push({2 , p});
        while(!q.empty()){
            auto p1 = q.top();
            q.pop();
            if(q.empty()){
                ret = p1.y;
                break;
            }
            auto p2 = q.top();
            q.pop();
            auto p3 = multiply(p1.y , p2.y);
            q.push({(int)p3.size() , p3});
        }
        return ret;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    f[0] = 1;
    for(int i = 1; i <= N; ++i)f[i] = mul(f[i - 1] , i);
    for(int i = 2; i <= N; ++i){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    DFS(1 , 1);
    for(int i = 1; i <= N; ++i){
        NTT::poly.push_back({1 , nc[i]});
    }
    vector<ll> P = NTT::solve(0 , NTT::poly.size() - 1);
    /*for(int j = 0; j <= N; ++j)dp[j][0] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j){
            dp[i][j] = add(dp[i][j] , dp[i - 1][j]);
            dp[i][j] = add(dp[i][j] , mul(dp[i - 1][j - 1] , nc[i]));
        }
    }
    ll ans = 0;
    for(int k = 0; k <= N - 1; ++k){
        ll sign = 1;
        if(k & 1)sign = -1;
        ll val = mul(sign , dp[N][k]);
        val = mul(val , f[N - k]);
        ans = add(ans , val);
    }*/
    ll ans = 0;
    for(int k = 0; k <= min(N - 1 , (int)P.size() - 1); ++k){
        ll sign = 1;
        if(k & 1)sign = -1;
        ll val = mul(sign , P[k]);
        val = mul(val , f[N - k]);
        ans = add(ans , val);
    }
    cout << ans << endl;
}
