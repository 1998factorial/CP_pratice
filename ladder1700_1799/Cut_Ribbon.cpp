#include <bits/stdc++.h>
using namespace std;
int N , A , B , C;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N >> A >> B >> C;
    vector<int> dp(N + 1 , -1);
    dp[0] = 0;
    for(int i = 1; i <= N; ++i){
        if(i - A >= 0 && ~dp[i - A]){
            dp[i] = max(dp[i] , dp[i - A] + 1);
        }
        if(i - B >= 0 && ~dp[i - B]){
            dp[i] = max(dp[i] , dp[i - B] + 1);
        }
        if(i - C >= 0 && ~dp[i - C]){
            dp[i] = max(dp[i] , dp[i - C] + 1);
        }
    }
    cout << dp[N] << endl;
}



