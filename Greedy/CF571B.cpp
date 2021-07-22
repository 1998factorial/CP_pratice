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
    int N , K;
    cin >> N >> K;
    vector<ll> a(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    // there will be K chains
    // N % K of them have length = N/K + 1
    // K - N % K of them have length = N/K
    // Greedy observation 1: sum{abs(a[i] - a[i+1])} is min when a[1..M] are sorted 
    // Greedy observation 2: sum{abs(a[i] - a[i+1])} + sum{abs(b[i] - b[i+1])} is minimal when they are disjoint
    // we can now do DP, using these 2 observations
    // observation 1 & 2 implies in optimal solution, all groups are sorted and disjoint
    // dp[i][j] = min cost to have i segments of type 1 and j of type 2
    sort(a.begin() + 1 , a.end());
    int N1 = N % K , N2 = K - N % K;
    vector<vector<ll>> dp(N1 + 1 , vector<ll>(N2 + 1 , inf64));
    dp[0][0] = 0;
    for(int i = 0; i <= N1; ++i){
        for(int j = 0; j <= N2; ++j){
            if(i > 0){
                dp[i][j] = min(dp[i][j] , dp[i - 1][j] + a[i * (N / K + 1) + j * (N / K)] - a[(i - 1) * (N / K + 1) + j * (N / K) + 1]);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j] , dp[i][j - 1] + a[i * (N / K + 1) + j * (N / K)] - a[i * (N / K + 1) + (j - 1) * (N / K) + 1]);
            }
        }
    }
    cout << dp[N1][N2] << endl;
}