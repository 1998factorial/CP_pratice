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
const int mod = 1e9 + 7;
int add(int x , int y){
    return ((ll)x + y) % mod;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
char a[705];
int dp[705][705][2] , X[705];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%s" , a + 1);
    int N = strlen(a + 1);
    for(int i = 1; i <= N; ++i)X[i] = a[i] - '0';
    int ans = 0;
    for(int d = 1; d <= 9; ++d){
        memset(dp , 0 , sizeof(dp));
        dp[0][0][1] = 1;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= i; ++j){
                for(int f = 0; f <= 1; ++f){
                    for(int nd = 0; nd <= 9; ++nd){
                        if(nd > X[i + 1] && f)continue;
                        int nf = f && nd == X[i + 1];
                        dp[i + 1][j + (nd >= d)][nf] = add(dp[i + 1][j + (nd >= d)][nf] , dp[i][j][f]);
                    }
                }
            }
        }
        for(int j = 1 , ones = 0; j <= N; ++j){
            ones = mul(ones , 10);
            ones = add(ones , 1);
            for(int f = 0; f <= 1; ++f){
                ans = add(ans , mul(dp[N][j][f] , ones));
            }
        }
    }
    printf("%d\n" , ans);
}