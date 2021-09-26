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
const int mod = 1e9 + 7;
int N , K;
int comp[105][105];
// 0 -> no
// 1 -> a[i] < a[j]
// 2 -> a[i] <= a[j]
// 3 -> a[i] == a[j]
// 4 -> a[i] >= a[j]
// 5 -> a[i] > a[j]
ll dp[105][105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= K; ++i){
        int l , r;
        string s;
        cin >> l >> s >> r;
        if(s == "<"){
            comp[l][r] = 1;
            comp[r][l] = 5;
        }
        if(s == "<="){
            comp[l][r] = 2;
            comp[r][l] = 4;
        }
        if(s == "="){
            comp[l][r] = 3;
            comp[r][l] = 3;
        }
        if(s == ">="){
            comp[l][r] = 4;
            comp[r][l] = 2;
        }
        if(s == ">"){
            comp[l][r] = 5;
            comp[r][l] = 1;
        }
    }
    // dp[l][r] = number of ways to put the last (r - l + 1) / 2 numbers into
    // a[l..r]
    for(int i = 1; i + 1 <= 2 * N; ++i){
        // can we put 2 N's in [i , i + 1] ?
        int ok = 1;
        if(comp[i][i + 1] == 5 || comp[i][i + 1] == 1)ok = 0;
        for(int j = 1; j < i; ++j){
            if(comp[j][i] >= 3)ok = 0;
            if(comp[j][i + 1] >= 3)ok = 0;
        }
        for(int j = i + 2; j <= 2 * N; ++j){
            if(comp[j][i] >= 3)ok = 0;
            if(comp[j][i + 1] >= 3)ok = 0;
        }
        dp[i][i + 1] = ok;
    }
    for(int len = 4; len <= 2 * N; len += 2){
        for(int l = 1; l + len - 1 <= 2 * N; ++l){
            int r = l + len - 1 , ok = 1;
            // put on (l , l + 1)
            if(comp[l][l + 1] == 5 || comp[l][l + 1] == 1)ok = 0;
            // all in [l + 2 , r] , should all >= a[l] , a[l + 1]
            for(int j = l + 2; j <= r; ++j){
                if(comp[l][j] >= 3)ok = 0;
                if(comp[l + 1][j] >= 3)ok = 0;
            }
            // all in [1 , l - 1] , should all <= a[l] , a[l + 1]
            for(int j = 1; j < l; ++j){
                if(comp[j][l] >= 3)ok = 0;
                if(comp[j][l + 1] >= 3)ok = 0;
            }
            // all in [r + 1 , 2 * N] , should all <= a[l] , a[l + 1]
            for(int j = r + 1; j <= 2 * N; ++j){
                if(comp[j][l] >= 3)ok = 0;
                if(comp[j][l + 1] >= 3)ok = 0;
            }
            if(ok && l + 2 <= r){
                dp[l][r] += dp[l + 2][r];
            }
            // put on (r - 1 , r)
            ok = 1;
            if(comp[r - 1][r] == 5 || comp[r - 1][r] == 1)ok = 0;
            // all in [l , r - 2] , should all >= a[r - 1] , a[r]
            for(int j = l; j <= r - 2; ++j){
                if(comp[r - 1][j] >= 3)ok = 0;
                if(comp[r][j] >= 3)ok = 0;
            }
            // all in [1 , l - 1] , should all <= a[r - 1] , a[r]
            for(int j = 1; j < l; ++j){
                if(comp[j][r - 1] >= 3)ok = 0;
                if(comp[j][r] >= 3)ok = 0;
            }
            // all in [r + 1 , 2 * N] , should all <= a[r - 1] , a[r]
            for(int j = r + 1; j <= 2 * N; ++j){
                if(comp[j][r - 1] >= 3)ok = 0;
                if(comp[j][r] >= 3)ok = 0;
            }
            if(ok && l <= r - 2){
                dp[l][r] += dp[l][r - 2];
            }
            ok = 1;
            // put on (l , r)
            if(comp[l][r] == 5 || comp[l][r] == 1)ok = 0;
            // all in [l + 1 , r - 1] , should all >= a[l] , a[r]
            for(int j = l + 1; j <= r - 1; ++j){
                if(comp[l][j] >= 3)ok = 0;
                if(comp[r][j] >= 3)ok = 0;
            }
            // all in [1 , l - 1] , should all <= a[l] , a[r]
            for(int j = 1; j < l; ++j){
                if(comp[j][l] >= 3)ok = 0;
                if(comp[j][r] >= 3)ok = 0;
            }
            // all in [r + 1 , 2 * N] , should all <= a[l] , a[r]
            for(int j = r + 1; j <= 2 * N; ++j){
                if(comp[j][l] >= 3)ok = 0;
                if(comp[j][r] >= 3)ok = 0;
            }
            if(ok && l + 1 <= r - 1){
                dp[l][r] += dp[l + 1][r - 1];
            }
        }
    }
    cout << dp[1][2 * N] << endl;
} 
