
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
int N;
string a[maxn];
int dp[505][505] , w[505][505];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= N; ++i){
        for(int j = i + 1; j <= N; ++j){
            int sz = a[j].size();
            w[i][j] = sz;
            for(int len = 1; len <= sz; ++len){
                int ok = 1;
                for(int k = 0; k < len; ++k){
                    if(a[j][k] != a[i][sz - len + k]){
                        ok = 0;
                    }
                }
                if(ok)w[i][j] = sz - len;
            }
        }
    }
    for(int i = 1; i <= N; ++i)w[0][i] = a[i].size();
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= N; ++j){
            dp[i][j] = inf32;
        }
    }
    dp[1][0] = a[1].size();
    for(int i = 2; i <= N; ++i){
        for(int j = 0; j < i - 1; ++j){
            dp[i][i - 1] = min(dp[i][i - 1] , dp[i - 1][j] + w[j][i]);
        }
        for(int j = 0; j < i - 1; ++j){
            dp[i][j] = dp[i - 1][j] + w[i - 1][i];
        }
    }
    int ans = inf32;
    for(int i = 0; i <= N - 1; ++i){
        ans = min(ans , dp[N][i]);
    }
    cout << ans << endl;
}   
// dp[i][j] = minimal total length if the first sequence ends with a[i]
// and the second ends with a[j]