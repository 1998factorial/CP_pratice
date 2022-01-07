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
const int maxv = 2e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
/*
This problem can be solved by dynamic programming, let 
dp[l][r] be the maximal score the first player can get
consider interval a[l..r], the first player can select a[l]
or a[r]. if he select a[l] then we are left with array 
a[l + 1 ... r], and now the second player become the first player
in the subgame. Similarly for the case when we choose a[r].
So dp[l][r] = max{sum[l + 1][r] - dp[l + 1][r] + a[l] , sum[l][r - 1] - dp[l][r - 1] + a[r]}

Here is the C++ code
*/
int a[100];
int sum[100];
int dp[100][100]; // maximal score we can get
int get_sum(int l , int r){
    return sum[r] - sum[l - 1];
}
int solve(int l , int r){
    if(l == r){
        return a[l];
    }
    int& ret = dp[l][r];
    if(~ret)return ret;
    ret = 0;
    ret = max(ret , get_sum(l + 1 , r) - solve(l + 1 , r) + a[l]);
    ret = max(ret , get_sum(l , r - 1) - solve(l , r - 1) + a[r]);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    memset(dp , -1 , sizeof(dp));
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int ret = solve(1 , N);
    if(sum[N] - ret < ret){
        cout << "First" << endl;
    }
    else if(sum[N] - ret == ret){
        cout << "Draw" << endl;
    }
    else {
        cout << "Second" << endl;
    }
}