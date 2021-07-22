#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N + 1) , sum(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i] , sum[i] = sum[i - 1] + a[i];
    vector<vector<int>> dp(N + 1 , vector<int> (N + 1 , inf32));
    vector<vector<int>> f(N + 1 , vector<int> (N + 1 , inf32));
    for(int i = 1; i <= N; ++i){
        dp[i][1] = i - 1;
    }    
    f[1][1] = 0;
    for(int i = 2; i <= N; ++i){
        for(int j = i; j > 1; --j){
            // for(int k = j - 1; k >= 1; --k){
            //     if(sum[i] - sum[j - 1] >= sum[j - 1] - sum[k - 1]){
            //         dp[i][j] = min(dp[i][j] , dp[j - 1][k] + i - j);
            //     }
            // }
            //f[i][j] = min{dp[i][i] , ... , dp[i][j]}
            int l = 1 , r = j - 1 , pos = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(sum[i] - sum[j - 1] >= sum[j - 1] - sum[mid - 1]){
                    pos = mid;
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            if(~pos){
                dp[i][j] = min(dp[i][j] , f[j - 1][pos] + i - j);
            }
        }
        for(int j = i; j >= 1; --j){
            f[i][j] = min(f[i][j + 1] , dp[i][j]);
        }
    }
    int ans = inf32;
    for(int i = 1; i <= N; ++i){
        ans = min(ans , dp[N][i]);
    }
    cout << ans << endl;
}   