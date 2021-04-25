#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

void add(ll& x , ll y){
    x += y;
    if(x >= mod)x -= mod;
}

void mul(ll& x , ll y){
    x *= y;
    x %= y;
}

int N , a[1005] , base = 10010;
ll dp[1005][20050];
// dp[i][j] = the number of all possible subarrays ending at i, with sum = j
// answer is just the sum of all dp[i][0]
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= N; ++i){
        dp[i][base + a[i]] = dp[i][base - a[i]] = 1;
        for(int j = -10000; j <= 10000; ++j){
            int cj = j + base;
            if(cj - a[i] >= 0){
                add(dp[i][cj] , dp[i - 1][cj - a[i]]);
            }
            if(cj + a[i] < 20050){
                add(dp[i][cj] , dp[i - 1][cj + a[i]]);
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= N; ++i){
        add(ans , dp[i][base]);
    }
    cout << ans << endl;
}