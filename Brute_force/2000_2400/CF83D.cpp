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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
map<int , map<int , int>> dp;
bool isPrime(int n){
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0)return false;
    }
    return true;
}
int solve(int n , int k){
    if(n < k || !isPrime(k))return 0;
    if((ll)k * k > n)return 1;
    if(dp[n].find(k) != dp[n].end())return dp[n][k];
    int ans = n / k;
    for(int i = 2; i < k; ++i){
        ans -= solve(n / k , i);
    }
    dp[n][k] = ans;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L , R , K;
    cin >> L >> R >> K;
    cout << solve(R , K) - solve(L - 1 , K) << endl;
}   
// dp[n][k] = number of x <= n such that the smallest divisor of x is k
// dp[n][k] = n / k - sum{dp[n / k][i] | 2 <= i <= k - 1}
// if n < k, dp[n][k] = 0
// if k is not a prime, then dp[n][k] = 0
// if k * k > n then dp[n][k] = 1
// so we have k <= sqrt(n) , first dimension is at most log(n) , second dimemsion is sqrt(n)
// total time complexity is about O(log(n) * sqrt(n)) ~ 1381772
