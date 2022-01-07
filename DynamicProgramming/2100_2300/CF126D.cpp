#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
vector<ll> fib;
// 1 , 2 , 3 , 5 , 8 , 13 , 21 ...
// 0 , 1 , 2 , 3 , 4 , 5 , 6 ...
void solve(){
    ll N;
    cin >> N;
    ll M = N;
    vector<ll> index; 
    for(int i = 85; i >= 0; --i){
        if(M >= fib[i]){
            M -= fib[i];
            index.push_back(i + 1);
        }
    }
    reverse(index.begin() , index.end());
    int sz = index.size();
    vector<vector<ll>> dp(sz , vector<ll>(2 , 0));
    dp[0][0] = 1;
    dp[0][1] = (index[0] - 1) / 2;
    for(int i = 1; i < sz; ++i){
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] * ((index[i] - index[i - 1] - 1) / 2) + dp[i - 1][1] * ((index[i] - index[i - 1]) / 2);
    }
    cout << dp[sz - 1][0] + dp[sz - 1][1] << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fib.push_back(1);
    fib.push_back(2);
    for(; fib[fib.size() - 1] + fib[fib.size() - 2] < inf64; ){
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
    // 86 fib numbers
    //cout << fib.size() << endl;
    assert(fib.back() + fib[fib.size() - 2] > inf64);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
} 