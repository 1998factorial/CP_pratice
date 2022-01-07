#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 1e5 + 10;
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
        // we can reduce dp[l][r][c] to dp[l][r]
        // as it is always optimal to colour everything from a[l..r] to a[l]
        vector<int> a(N + 5);
        vector<int> b; b.push_back(0);
        vector<int> pos[N + 5];
        for(int i = 1; i <= N; ++i)cin >> a[i];
        for(int i = 1; i <= N; ++i){
            if(a[i] != a[i - 1])b.push_back(a[i]);
        }
        a = b;
        N = a.size() - 1;
        vector<vector<int>> dp(N + 5 , vector<int> (N + 5 , 0));
        for(int i = 1; i <= N; ++i){
            pos[a[i]].push_back(i);
        }
        for(int len = 2; len <= N; ++len){
            for(int i = 1; i + len - 1 <= N; ++i){
                int j = i + len - 1;
                dp[i][j] = max(dp[i][j] , dp[i + 1][j]);
                for(int k : pos[a[i]]){
                    if(i + 1 <= k && k <= j){
                        dp[i][j] = max(dp[i][j] , dp[i + 1][k - 1] + 1 + dp[k][j]);
                    }
                }
            }
        }
        cout << N - 1 - dp[1][N] << endl;
    }
} 