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
int add(int x , int y){
    return ((ll)x + y) % mod;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<vector<int>> dp(2 , vector<int>(maxn));
    vector<int> vals[2];
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for(int i = 1; i <= N; ++i)cin >> a[i];
        int ans = 0;
        for(int i = N; i >= 1; --i){
            for(int j : vals[i & 1])dp[i & 1][j] = 0;
            vals[i & 1].clear();
            dp[i & 1][a[i]] = 1;
            vals[i & 1].push_back(a[i]);
            int last = a[i];
            for(int j : vals[(i + 1) & 1]){
                int inc = ceil((double)a[i] / j);
                int nj = a[i] / inc;
                ans = add(ans , mul(inc - 1 , mul(i , dp[(i + 1) & 1][j])));
                dp[i & 1][nj] = add(dp[i & 1][nj] , dp[(i + 1) & 1][j]);
                if(last != nj){
                    vals[i & 1].push_back(nj);
                    last = nj;
                }
            }
        }  
        cout << ans << endl;
        for(int j : vals[0])dp[0][j] = dp[1][j] = 0;
        for(int j : vals[1])dp[0][j] = dp[1][j] = 0;
        vals[0].clear(); vals[1].clear();
    }
} 