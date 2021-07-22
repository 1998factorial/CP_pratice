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
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
char b[41][401];
int N , M , f[402][42][42] , cost[405][45][45][12];
// f[i][l][r] = the minimal cost to make 
// a[l][i...M] to a[r][i...M] non-decreasing
// cost[i][l][r][d] = the number of a[l..r][i] != d
int solve(int pos , int l , int r , int flag){
    if(pos > M)return 0;
    if(l >= r)return 0;
    int& ret = f[pos][l][r];
    if(~ret && !flag)return ret;
    ret = inf32;
    vector<vector<int>> dp(11 , vector<int>(r - l + 2 , inf32));
    vector<vector<int>> pre(11 , vector<int>(r - l + 2 , -1));
    // dp[i][j] = minimal number of operations needed
    // to use first i digits to cover the first j numbers
    for(int i = 0; i <= 10; ++i)dp[i][0] = 0;
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= r - l + 1; ++j){
            for(int k = 0; k <= j; ++k){
                int val = dp[i - 1][k] + cost[pos][l + k][l + j - 1][i - 1] + solve(pos + 1 , l + k , l + j - 1 , 0);
                if(dp[i][j] > val){
                    dp[i][j] = val;
                    pre[i][j] = k;
                }
            }
        }
    }
    int best_digit = 10 , cur = r - l + 1;
    for(int i = 0; i <= 10; ++i){
        if(ret > dp[i][r - l + 1]){
            ret = dp[i][r - l + 1];
            best_digit = i;
        }
    }
    if(flag)
    while(best_digit >= 0 && cur >= 0 && ~pre[best_digit][cur]){
        int ncur = pre[best_digit][cur];
        for(int k = cur; k > ncur; --k){
            b[l + k - 1][pos] = '0' + best_digit - 1;
        }
        solve(pos + 1 , ncur + l , cur + l - 1 , flag);
        --best_digit;
        cur = ncur;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> (b[i] + 1);
    }
    memset(f , -1 , sizeof(f));
    memset(cost , 0 , sizeof(cost));
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j){
            for(int k = j; k <= N; ++k){
                for(int d = 0; d < 10; ++d){
                    for(int x = j; x <= k; ++x){
                        if(b[x][i] - '0' != d){
                            ++cost[i][j][k][d];
                        }
                    }
                }
            }
        }
    }
    solve(1 , 1 , N , 1);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cout << b[i][j];
        }
        cout << endl;
    }
}