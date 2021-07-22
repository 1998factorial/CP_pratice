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
const ll mod = 1e9 + 7;
vector<ll> v , p , sum;
ll gcd(ll x , ll y){
    return x == 0 ? y : gcd(y % x , x);
}
ll lcm(ll x , ll y){
	return x * y / gcd(x , y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
	cin >> t;
	while(t--){
        ll N;
		cin >> N;
		ll v = 1 , ans = 0;
		for(ll fx = 1; fx <= 42; ++fx){
			v = lcm(v , fx);
			//printf("#[f[x] >= %lld] = %lld\n" , fx , N / v);
			ans += N / v;
			ans %= mod;
		}
		cout << (ans + N) % mod << endl;
	}
}