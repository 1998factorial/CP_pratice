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
const int maxv = 5e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int cnt[maxv] , N , up = 0;
ll dp[maxv];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        int x;
        cin >> x;
        up = max(up , x);
        ++cnt[x];
    }
    for(int i = 1; i <= up; ++i){
        for(int j = i * 2; j <= up; j += i){
            cnt[i] += cnt[j];
        }
    }
    // dp[i] = maximal value if we end with i
    for(int i = 1; i <= up; ++i)dp[i] = (ll)i * cnt[i];
    for(int i = up; i >= 1; --i){
        for(int j = 2 * i; j <= up; j += i){
            dp[i] = max(dp[i] , dp[j] + (ll)(cnt[i] - cnt[j]) * i);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= up; ++i)ans = max(ans , dp[i]);
    cout << ans << endl;
}