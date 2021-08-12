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
const int maxn = 65555;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18;
const int mod = 1e9 + 7;
char c[16];
int r[16] , b[16] , N , dp[maxn][17 * 17];
// dp[mask][i] = when we own card set = mask, and we have saved i tokens
// on reds, what is the maximal amount of blue token we can save?
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> c[i] >> r[i] >> b[i];
    }
    int limit = (1 << N) - 1;
    for(int mask = 0; mask <= limit; ++mask){
        for(int i = 0; i <= N * N; ++i){
            dp[mask][i] = -inf32;
        }
    }
    dp[0][0] = 0;
    for(int mask = 0; mask < limit; ++mask){
        int R = 0 , B = 0;
        for(int i = 0; i < N; ++i){
            if(mask >> i & 1){
                R += c[i] == 'R';
                B += c[i] == 'B';
            }
        }
        //maximal amount of red tokens saved = - 0 - 1 - 2 - .. - (R - 1)
        //maximal amount of blue tokens saved = - 0 - 1 - 2 - .. - (B - 1)
        for(int j = 0; j <= N * N; ++j){    
            if(dp[mask][j] < 0)continue;
            for(int i = 0; i < N; ++i){
                if(mask >> i & 1)continue;
                int nmask = mask | (1 << i);
                int saved_red = r[i] - max(r[i] - R , 0);
                int saved_blue = b[i] - max(b[i] - B , 0);
                if(j + saved_red <= N * N){
                    dp[nmask][j + saved_red] = max(dp[nmask][j + saved_red] , dp[mask][j] + saved_blue);
                }
            }
        }
    }
    int ans = inf32;
    int red_sum = 0 , blue_sum = 0;
    for(int i = 0; i < N; ++i){
        red_sum += r[i];
        blue_sum += b[i];
    }
    for(int i = 0; i <= N * N; ++i){
        if(dp[limit][i] < 0)continue;
        ans = min(ans , max(red_sum - i , blue_sum - dp[limit][i]));
    }
    cout << ans + N << endl; // need N rounds to buy cards
}    