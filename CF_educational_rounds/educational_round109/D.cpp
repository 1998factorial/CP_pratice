#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N + 1) , sum(N + 1) , R(N + 1 , -1) , L(N + 1 , -1) , used(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i] , sum[i] = sum[i - 1] + a[i];
    for(int i = N; i >= 1; --i){
        if(a[i])
        for(int j = i + 1; j <= N; ++j){
            if(!a[j] && !used[j]){
                R[i] = j;
                used[j] = 1;
                break;
            }
        }
    }
    for(int i = 1; i <= N; ++i)used[i] = 0;
    for(int i = 1; i <= N; ++i){
        if(a[i])
        for(int j = i - 1; j >= 1; --j){
            if(!a[j] && !used[j]){
                L[i] = j;
                used[j] = 1;
                break;
            }
        }
    }
    vector<vector<int>> LL(N + 1 , vector<int> (N + 1 , inf32));
    vector<vector<int>> RR(N + 1 , vector<int> (N + 1 , inf32));
    for(int i = 1; i <= N; ++i){
        if(!a[i])LL[i][i] = RR[i][i] = 0;
    }
    for(int len = 2; len <= N; ++len){
        for(int i = 1; i + len - 1 <= N; ++i){
            int j = i + len - 1;
            if(a[i] && ~R[i] && R[i] <= j){
                RR[i][j] = min(RR[i][j] , RR[i + 1][j] + R[i] - i);
            }
            if(a[j] && ~L[j] && L[j] >= i){
                LL[i][j] = min(LL[i][j] , LL[i][j - 1] + j - L[j]);
            }
            if(a[i] == 0){
                RR[i][j] = min(RR[i][j] , RR[i + 1][j]);
                LL[i][j] = min(LL[i][j] , LL[i + 1][j]);
            }
            if(a[j] == 0){
                RR[i][j] = min(RR[i][j] , RR[i][j - 1]);
                LL[i][j] = min(LL[i][j] , LL[i][j - 1]);
            }
        }
    }
    vector<int> dp(N + 1 , inf32);
    dp[0] = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < i; ++j){
            dp[i] = min(dp[j] + min(LL[j + 1][i] , RR[j + 1][i]) , dp[i]);
        }
    }
    cout << dp[N] << endl;
}