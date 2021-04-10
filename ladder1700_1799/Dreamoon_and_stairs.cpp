#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
int N , M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N >> M;
    vector<vector<int>> dp(N + 1 , vector<int>(M , inf));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(i + 1 <= N){
                dp[i + 1][(j + 1) % M] = min(dp[i + 1][(j + 1) % M] , dp[i][j] + 1);
            }
            if(i + 2 <= N){
                dp[i + 2][(j + 1) % M] = min(dp[i + 2][(j + 1) % M] , dp[i][j] + 1);
            }
        }
    }
    int ans = (dp[N][0] >= inf) ? -1 : dp[N][0];
    cout << ans << endl;
}