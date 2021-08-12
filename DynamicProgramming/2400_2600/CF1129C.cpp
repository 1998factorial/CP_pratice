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
const int mod = 1e9 + 7;
char s[3005];
int N , dp[3005][3005] , LCS[3005][3005];
// "0011", "0101", "1110", "1111"
// LCS --- longest common suiffix
int add(int x , int y){
    ll ans = x;
    ans += y;
    if(ans >= mod)ans -= mod;
    return ans;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
bool ok(int pos){
    if(s[pos - 3] == '0' && s[pos - 2] == '0' && s[pos - 1] == '1' && s[pos] == '1')return false;
    if(s[pos - 3] == '0' && s[pos - 2] == '1' && s[pos - 1] == '0' && s[pos] == '1')return false;
    if(s[pos - 3] == '1' && s[pos - 2] == '1' && s[pos - 1] == '1' && s[pos] == '0')return false;
    if(s[pos - 3] == '1' && s[pos - 2] == '1' && s[pos - 1] == '1' && s[pos] == '1')return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> s[i];
    }
    for(int i = 1; i <= N; ++i){
        dp[i][i] = dp[i][i - 1] = 1;
    }
    for(int len = 2; len <= N; ++len){
        for(int i = 1; i + len - 1 <= N; ++i){
            int j = i + len - 1;
            if(len < 4){
                dp[i][j] = 1 << (len - 1);
            }
            else if(len == 4){
                if(ok(j)){
                    dp[i][j] = 1 << 3;
                }   
                else{
                    dp[i][j] = (1 << 3) - 1;
                }
            }
            else{
                for(int k = 1; k <= 3; ++k){
                    dp[i][j] = add(dp[i][j] , dp[i][j - k]);
                }
                if(ok(j)){
                    dp[i][j] = add(dp[i][j] , dp[i][j - 4]);
                }
            }
            //printf("dp[%d][%d] = %d\n" , i , j , dp[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = i; j >= 1; --j){
            if(i == j){
                LCS[i][j] = i;
            }
            else if(s[i] == s[j]){
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            //printf("LCS[%d][%d] = %d\n" , i , j , LCS[i][j]);
        }
    }
    for(int i = 1; i <= N; ++i){
        int len = 0;
        for(int j = 1; j < i; ++j){
            len = max(len , LCS[i][j]);
        }
        //printf("max_len = %d\n" , len);
        for(int j = 1; j < i - len + 1; ++j){
            //printf("+= [%d %d] = %d\n" , j , i , dp[j][i]);
            ans = add(ans , dp[j][i]);
        }
        cout << ans << endl;
    }
}   
