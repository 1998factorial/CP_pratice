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
    int N;
    cin >> N;
    vector<ll> a(N + 1) , b(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    sort(a.begin() + 1 , a.end());
    for(int i = 1; i <= N; ++i)b[i] = a[N] - a[i];
    vector<vector<ll>> dp(65 , vector<ll> (N + 1 , inf64));
    dp[0][0] = 0;
    for(int i = 0; i < 64; ++i){
        ll mod = (1ll << (i));
        vector<int> id(N);
        for(int j = 0; j < N; ++j)id[j] = j + 1;
        sort(id.begin() , id.end() , [&](int& l , int& r){
            return b[l] % mod < b[r] % mod;
        });
        vector<vector<int>> sum(N + 1 , vector<int>(2 , 0));
        for(int j = 0; j < N; ++j){
            int v = b[id[j]] >> (i) & 1;
            ++sum[j + 1][v];
        }
        for(int j = 1; j <= N; ++j){
            for(int k = 0; k < 2; ++k){
                sum[j][k] += sum[j - 1][k];
            }
        }
        for(int j = 0; j <= N; ++j){
            if(dp[i][j] >= inf64)continue;
            // j carries , N - j zeros
            // [1 , N - j] [N - j + 1 , N] ones
            int nj , cost;
            // if t[i + 1] is 0
            // only bits are 1s and have carry
            nj = sum[N][1] - sum[N - j][1];
            // bits are 0s and have carry + bits are 1s and no carry
            cost = (sum[N][0] - sum[N - j][0]) + sum[N - j][1];
            dp[i + 1][nj] = min(dp[i + 1][nj] , dp[i][j] + cost);
            // if t[i + 1] is 1
            // bits are 1s and no carry + bits are 1s and have carry + bits are 0 and have carry 
            nj = sum[N][1] + (sum[N][0] - sum[N - j][0]);
            // bits are 1s and have carry + bits are 0 and have no carry
            cost = (sum[N][1] - sum[N - j][1]) + sum[N - j][0];
            dp[i + 1][nj] = min(dp[i + 1][nj] , dp[i][j] + cost);
        }
    }
    cout << dp[64][0] << endl;
}   