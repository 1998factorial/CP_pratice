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
const int maxn = 510;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<ll> a(N) , b(N);
    for(int i = 0; i < N; ++i)cin >> a[i];
    sort(a.begin() , a.end());
    for(int i = 0; i < N; ++i)b[i] = a[N - 1] - a[i];
    vector<vector<ll>> dp(65 , vector<ll> (N + 1 , inf64));
    vector<vector<int>> sum(N + 1 , vector<int>(2));
    dp[0][0] = 0;
    for(int i = 1; i <= 63; ++i){
        int current_bit = i - 1;
        vector<int> p(N);
        for(int j = 0; j < N; ++j)p[j] = j;
        sort(p.begin() , p.end() , [&](int& l , int& r){
            return b[l] % (1ll << current_bit) < b[r] % (1ll << current_bit);
        });
        for(int j = 0; j <= N; ++j){
            for(int k = 0; k < 2; ++k){
                sum[j][k] = 0;
            }
        }
        for(int j = 1; j <= N; ++j){
            ++sum[j][b[p[j - 1]] >> current_bit & 1];
        }
        for(int j = 1; j <= N; ++j){
            for(int k = 0; k < 2; ++k){
                sum[j][k] += sum[j - 1][k];
            }
        }
        for(int j = 0; j <= N; ++j){
            // enumerate the number of carries that we have
            // try current_bit of t = 0
            int new_carry = sum[N][1] - sum[N - j][1];
            int cost = sum[N - j][1] + sum[N][0] - sum[N - j][0];
            dp[i][new_carry] = min(dp[i][new_carry] , dp[i - 1][j] + cost);
            // try current_bit of t = 1
            new_carry = sum[N][1] - sum[N - j][1] + sum[N][0] - sum[N - j][0] + sum[N - j][1];
            cost = sum[N - j][0] + sum[N][1] - sum[N - j][1];
            dp[i][new_carry] = min(dp[i][new_carry] , dp[i - 1][j] + cost);
        }
    }
    cout << dp[63][0] << endl;
}       
// goal is to min{bitcount[x - a[i]] | max{a[i]} <= x}
// transform to min{bitcount[t + a[N - 1] - a[i]]} , min{bitcount[t + b[i]]}
// now consider value of each bit of t 
// then use dp to store these information
// dp[i][j] = the minimal number of 1s in first i bits and we have j carries
// sort b[k] mod (2^i) 
// note that carries will only exist in the suffix