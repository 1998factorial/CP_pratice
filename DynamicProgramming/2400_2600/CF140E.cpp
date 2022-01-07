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
int N , M , P , L[maxv] , dp[2][5005] , f[5005][5005] , sum[maxv] , A[5005] , F[5005];
int add(int x , int y){
    ll ans = (ll)x + y;
    return ans % P;
}
int sub(int x , int y){
    ll ans = (ll)x - y;
    return ((ans % P) + P) % P;
}
int mul(int x , int y){
    ll ans = (ll)x * y;
    return ans % P;
}
// f[i][j] = # of colouring for length i , using j colours
// st no two adjcent cells have the same colour
// dp[i][j] = # of good colouring for the first i layers , 
// st the ith layer has j colours
// A[M][j] = M! / (M-j)! = M * (M - 1) * ... * (M - j + 1)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> P;
    for(int i = 1; i <= N; ++i)cin >> L[i];
    A[0] = 1;
    for(int i = 1; i <= min(M , 5000); ++i){
        A[i] = mul(A[i - 1] , M - i + 1);
    }
    F[0] = 1;
    for(int i = 1; i <= 5000; ++i){
        F[i] = mul(F[i - 1] , i);
    }
    f[0][0] = 1;
    for(int i = 1; i <= 5000; ++i){
        for(int j = 1; j <= i; ++j){
            f[i][j] = add(f[i][j] , f[i - 1][j - 1]);
            f[i][j] = add(f[i][j] , mul(f[i - 1][j] , j - 1));
        }
    }
    dp[0][0] = sum[0] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= min(M , L[i]); ++j){
            dp[i & 1][j] = mul(sum[i - 1] , mul(f[L[i]][j] , A[j]));
            // subtract the case when layer i - 1 and layer i have the same 
            // colour set
            if(j <= L[i - 1]){
                dp[i & 1][j] = sub(dp[i & 1][j] , mul(mul(dp[(i - 1) & 1][j] , F[j]) , f[L[i]][j]));
            }
            sum[i] = add(sum[i] , dp[i & 1][j]);
        }
    }
    cout << sum[N] << endl;
} 