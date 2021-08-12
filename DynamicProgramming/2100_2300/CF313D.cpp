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
const int maxn = 310;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , M , K;
int cost[maxn][maxn];
ll dp[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cost[i][j] = inf32;
        }
    }
    for(int i = 1; i <= M; ++i){
        int l , r , c;
        cin >> l >> r >> c;
        if(cost[l][r] > c){
            cost[l][r] = c;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 2; j <= i; ++j){
            cost[j][i] = min(cost[j][i] , cost[j - 1][i]);
        }
    }
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= K; ++j){
            dp[i][j] = inf64;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= K; ++j){
            dp[i][j] = min(dp[i][j] , dp[i - 1][j]);
            for(int k = 1; k <= i; ++k){
                if(cost[k][i] == inf32)continue;
                dp[i][j] = min(dp[i][j] , dp[k - 1][max(0 , j - (i - k + 1))] + cost[k][i]);
            }
        }
    }
    ll ans = inf64;
    ans = dp[N][K];
    if(ans >= inf64)ans = -1;
    cout << ans << endl;
}   
