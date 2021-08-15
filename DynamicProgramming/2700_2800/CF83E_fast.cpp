
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
int N , M , limit , dp[25][1 << 20] , bit_val[maxn];
string a[maxn];
int get_prefix(int v , int k){
    return bit_val[v] >> (M - k);
}
int get_suffix(int v , int k){
    return bit_val[v] & ((1 << k) - 1);
}
int cal(int i , int j){
    for(int x = M; x ;--x){
        if(get_suffix(i , x) == get_prefix(j , x)){
            return x;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        for(int j = 0; j < a[i].size(); ++j){
            bit_val[i] = 2 * bit_val[i] + (a[i][j] - '0');
        }
    }
    M = a[1].size();
    limit = (1 << M) - 1;
    for(int j = 0; j <= M; ++j){
        for(int mask = 0; mask <= limit; ++mask){
            dp[j][mask] = inf32;
        }
    }
    dp[0][0] = M;
    int sum = 0;
    for(int i = 2; i <= N; ++i){
        int v = M - cal(i - 1 , i);
        int tmp = inf32;
        for(int k = 0; k <= M; ++k){
            tmp = min(tmp , dp[k][get_prefix(i , k)] + M - k - v);
        }
        for(int k = 0; k <= M; ++k){
            dp[k][get_suffix(i - 1 , k)] = min(dp[k][get_suffix(i - 1 , k)] , tmp);
        }
        sum += v;
    }
    int ans = inf32;
    for(int j = 0; j <= M; ++j){
        for(int mask = 0; mask <= limit; ++mask){
            ans = min(ans , dp[j][mask]);
        }
    }
    cout << ans + sum << endl;
}   