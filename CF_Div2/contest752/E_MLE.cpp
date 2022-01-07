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
const ll mod = 998244353;
int a[maxn] , N;
int f(int i , int j){
    int ans = 0 , b = a[j];
    for(int k = j - 1; k >= i; --k){
        if(a[k] <= b){
            b = a[k];
            continue;
        }
        int n = a[k] / b + (a[k] % b != 0);
        b = a[k] / n;
        ans += n - 1;
    }
    return ans;
}

int add(int x , int y){
    return ((ll)x + y) % mod;
}

int mul(int x , int y){
    return (ll)x * y % mod;
}

vector<unordered_map<int , int>> dp;

int solve(int pos , int val){
    if(pos <= 0)return 0;
    if(dp[pos].find(val) != dp[pos].end())return dp[pos][val];
    int& ans = dp[pos][val];
    ans = 0;
    int n = ceil((double)a[pos] / val);
    int v = solve(pos - 1 , a[pos] / n);
    v = add(v , mul(n - 1 , pos));
    ans = add(v , ans);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        ll ans = 0;
        for(int i = 1; i <= N; ++i)cin >> a[i];
        dp = vector<unordered_map<int , int>> (N + 1);
        // dp[i][j] = the total sum of good numbers of non-decreasing array
        // for all subarray ending at a[i] , where each number is at most j
        for(int i = 1; i <= N; ++i){
            ans = add(ans , solve(i - 1 , a[i]));
        }
        cout<<ans<<endl;
    }
} 