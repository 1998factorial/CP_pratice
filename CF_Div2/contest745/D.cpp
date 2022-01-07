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
int N , M , K , P , fac[105] , dp[105][105][105] , C[105][105];
/*
p(m) = true iff there are exactly m different maximums in the set of 
all subsegments that contain x

dp[n][m][k] = the number of permutation of length n
such that there are exactly k numbers that staisfy p(m)

dp[n][m][k] = C(n - 1 , i - 1) * dp[i - 1][m - 1][x] * dp[n - i][m - 1][k - x]
for 1 <= i <= n , 0 <= x <= k

for all dp[n][1][1] = n! , because except x = n , all other x's will not satisfy p(m)

if m >= 2, k can not be greater then (N + 1) / 2 , intuitivly, as m grows bigger
we should expect k to be smaller. take m = 2 , [1 , 2] [3 , 4] [5 , 6]
we can not have k > 3
*/
int mul(int x , int y){
    ll ans = (ll)x * y;
    return ans % P;
}
int add(int x , int y){
    ll ans = (ll)x + y;
    if(ans >= P)ans -= P;
    return ans;
}
int solve(int n , int m , int k){
    if(m >= 2 && k > (n + 1) / 2)return 0;
    if(n == 0)return k == 0;
    if(n == 1)return (m == 1 && k == 1) || (m != 1 && k == 0);
    if(m == 1)return k == 1 ? fac[n] : 0;
    int& ans = dp[n][m][k];
    if(~ans)return ans;
    ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int x = 0; x <= k; ++x){
            int v = mul(C[n - 1][i - 1] , mul(solve(i - 1 , m - 1 , x) , solve(n - i , m - 1 , k - x)));
            ans = add(ans , v);
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K >> P;
    fac[0] = 1;
    for(int i = 1; i <= N; ++i)fac[i] = mul(fac[i - 1] , i);
    C[0][0] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = add(C[i - 1][j] , C[i - 1][j - 1]);
            }
        }
    }
    memset(dp , -1 , sizeof(dp));
    cout << solve(N , M , K) << endl;
} 