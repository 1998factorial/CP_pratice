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
mint dp[2][2005][2005] , sum[2][2005][2005] , f[5005] , invf[5005];

mint C(int n , int r){
    if(n < 0 || r < 0 || n < r)return 0;
    return f[n] * invf[n - r] * invf[r];
}

mint qpow(ll x , ll n){
    mint ret = 1;
    while(n){
        if(n & 1)ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

// dp[first i elements][mex of first i = j][k distinct value > j]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	f[0] = 1;
	for(int i = 1; i <= 5000; ++i)f[i] = f[i - 1] * i;
	for(int i = 0; i <= 5000; ++i)invf[i] = inv(f[i]);
    cin >> N >> K;
	for(int i = 1; i <= N; ++i){
		cin >> b[i];
		L[i] = max(0 , b[i] - K);
		R[i] = min(N , b[i] + K);
	}
	dp[0][0][0] = 1;
	for(int i = 1; i <= N; ++i){
		memset(dp[1] , 0 , sizeof(dp[1]));	
		for(int j = L[i]; j <= R[i]; ++j){
			for(int k = 0; k <= i; ++k){
				// mex unchange , k don't change , we have j + k choices here
				dp[1][j][k] += dp[0][j][k] * (j + k);  
				// mex unchange , we choose one more big number
				if(k)dp[1][j][k] += dp[0][j][k - 1];
				// change mex
				for(int pj = L[i - 1]; pj <= R[i - 1] && pj <= j - 1; ++pj){
					int choose = j - pj - 1;
					// dp[nk][j - choose] += dp[k][j] * (j)! / (j - choose)!
					if(k + choose <= i){
						dp[1][j][k] += dp[0][pj][k + choose] * f[k + choose] * invf[k];
					}
				}
			}
		}
		swap(dp[0] , dp[1]);
	}
	mint ans = 0;
	for(int j = L[N]; j <= R[N]; ++j){
		for(int k = 0; k <= N; ++k){
			ans += dp[0][j][k] * f[N - j] * invf[N - j - k];
		}
	}
	cout << ans << endl;
}