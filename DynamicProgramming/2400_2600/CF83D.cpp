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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int L , R , K;
map<int , map<int , int>> dp;
bool isprime(int n){
    for(int i = 2; (ll)i * i <= n; ++i){
        if(n % i == 0)return 0;
    }
    return 1;
}
int solve(int n , int k){
    if(n < k)return 0;
    if(n < 2)return 0;
    if(!isprime(k))return 0;
    if((ll)k * k > n)return 1;
    if(dp[n].find(k) != dp[n].end())return dp[n][k];
    int ans = n / k;
    for(int i = 2; i < k; ++i){
        ans -= solve(n / k , i);
    }
    return dp[n][k] = ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> L >> R >> K;
    cout << solve(R , K) - solve(L - 1 , K) << endl;
}