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
const int maxn = 1e6 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , A , B;
int a[maxn];
ll dp[maxn][3];
// dp[i][j] = min cost to make gcd of the a[1 .. i] = d
// j = 0 => we have not erased any thing yet
// j = 1 => we have erased a[i]
// j = 2 => we did not erase a[i] but we have erased some segment before
ll solve(int p){
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= 2; ++j){
            dp[i][j] = inf64;
        }
    }
    // force to keep a[1]
    dp[1][0] = 0;
    for(int i = 2; i <= N; ++i){
        for(int j = -1; j <= 1; ++j){
            int v = a[i] + j;
            ll c = (j != 0) ? B : 0;
            if(v % p == 0){
                // keep a[i]
                dp[i][0] = min(dp[i][0] , dp[i - 1][0] + c);
                dp[i][2] = min(dp[i][2] , min(dp[i - 1][1] , dp[i - 1][2]) + c);
                // do not keep a[i]
                dp[i][1] = min(dp[i][1] , min(dp[i - 1][0] , dp[i - 1][1]) + A);
            }
            else{
                // we can not keep a[i] in this case
                dp[i][1] = min(dp[i][1] , min(dp[i - 1][0] , dp[i - 1][1]) + A);
            }
        }
    }
    ll ans = inf64;
    for(int i = 0; i < 3; ++i)ans = min(ans , dp[N][i]);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> A >> B;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    // in all optimal solution
    // we will not delete both a[1] and a[N]
    // so we can brute force on the cases that we have
    // keeping a[1] : a[1] - 1 , a[1] , a[1] + 1 and the min cost
    // keeping a[N] : a[N] - 1 , a[N] , a[N] + 1 and the min cost
    ll ans = inf64;
    for(int k = 0; k < 2; ++k){
        for(int j = -1; j <= 1; ++j){
            int v = a[1] + j;
            vector<int> primes;
            for(ll i = 2; i * i <= v; ++i){
                if(v % i == 0){
                    primes.push_back(i);
                    while(v % i == 0){
                        v /= i;
                    }
                }
            }
            if(v > 1){
                primes.push_back(v);
            }
            for(int k : primes){
                ll c = (j != 0) ? B : 0;
                ans = min(ans , solve(k) + c);
            }
        }
        reverse(a + 1 , a + 1 + N);
    }
    cout << ans << endl;
}   
