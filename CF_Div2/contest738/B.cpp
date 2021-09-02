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
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        string a;
        cin >> a;
        vector<vector<int>> dp(N , vector<int>(2 , N + 10));
        vector<vector<int>> pre(N , vector<int>(2 , -1));
        if(a[0] == '?')dp[0][1] = dp[0][0] = 0;
        if(a[0] == 'R')dp[0][0] = 0;
        if(a[0] == 'B')dp[0][1] = 0;
        for(int i = 1; i < N; ++i){
            if(a[i] == '?'){
                dp[i][0] = min(dp[i - 1][0] + 1 , dp[i - 1][1]);
                pre[i][0] = (dp[i - 1][0] + 1 < dp[i - 1][1]) ? 0 : 1;
                dp[i][1] = min(dp[i - 1][1] + 1 , dp[i - 1][0]);
                pre[i][1] = (dp[i - 1][1] + 1 < dp[i - 1][0]) ? 1 : 0;
            }
            if(a[i] == 'R'){
                dp[i][0] = min(dp[i - 1][0] + 1 , dp[i - 1][1]);
                pre[i][0] = (dp[i - 1][0] + 1 < dp[i - 1][1]) ? 0 : 1;
            }
            if(a[i] == 'B'){
                dp[i][1] = min(dp[i - 1][1] + 1 , dp[i - 1][0]);
                pre[i][1] = (dp[i - 1][1] + 1 < dp[i - 1][0]) ? 1 : 0;
            }
        }
        int i = N - 1 , j = (dp[N - 1][0] < dp[N - 1][1]) ? 0 : 1;
        string ans = "";
        for(; i >= 0; --i){
            ans += (j == 0) ? 'R' : 'B';
            j = pre[i][j];
        }
        reverse(ans.begin() , ans.end());
        cout << ans << endl;
    }
}   