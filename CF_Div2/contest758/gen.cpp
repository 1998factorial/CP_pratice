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
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; 
 
struct mint {
	ll v; explicit operator ll() const { return v; }
	mint() { v = 0; }
	mint(int _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	mint(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
    mint operator++(int) { v++; if (v == MOD) v = 0; return mint(v); }
    mint operator--(int) { v--; if (v < 0) v = MOD - 1; return mint(v); }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mint& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};

int b[2005] , L[2005] , R[2005] , N , K;
int dp[2][2005][2005] , sum[2][2005][2005] , f[5005] , invf[5005];

mint C(int n , int r){
    if(n < 0 || r < 0 || n < r)return 0;
    return f[n] * invf[n - r] * invf[r];
}


// dp[first i elements][mex of first i = j][k distinct value > j]

int mul(int x , int y){
    ll v = (ll)x * y % MOD;
    return v;
}

int add(int x , int y){
    ll v = (ll)x + y;
    return v % MOD;
}

int qpow(ll x , ll n){
    int ret = 1;
    while(n){
        if(n & 1)ret = mul(ret , x);
        x = mul(x , x);
        n >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N = 2000 , K = 50;
    cout << N << " " << K << endl;
    for(int i = 1; i <= N; ++i){
        cout << 50 << " ";
    }
    cout << endl;
}