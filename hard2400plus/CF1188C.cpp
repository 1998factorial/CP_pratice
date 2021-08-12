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
const int inf32 = 1e9;
const ll inf64 = 1e18;
const int mod = 998244353;
int mul(int x , int y){
    return (ll)x * y % mod;
}
int add(int x , int y){
    ll ret = x;
    ret += y;
    if(ret >= mod)ret -= mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , K;
    cin >> N >> K;
    vector<int> a(N + 1);
    int up = 0;
    for(int i = 1; i <= N; ++i)cin >> a[i] , up = max(up , a[i]);
    sort(a.begin() + 1 , a.end());
    a[0] = 0;
    ll ans = 0;
    vector<int> pre(N + 1);
    vector<vector<int>> f(N + 1 , vector<int>(K + 1 , 0));
    vector<vector<int>> sum(N + 1 , vector<int>(K + 1 , 0));
    for(int x = 1; x <= up / (K - 1) + 1; ++x){
        // count the number of subsequences of length where it's value >= x
        // O(10^5 / K * N * K)
        for(int i = 0; i <= N; ++i){
            for(int j = 0; j <= K; ++j){
                f[i][j] = sum[i][j] = 0;
            }
        }
        f[0][0] = sum[0][0] = 1;
        for(int i = 1; i <= N; ++i)sum[i][0] += sum[i - 1][0];
        int p = 0;
        for(int i = 1; i <= N; ++i){
            while(p + 1 <= i && a[i] - a[p + 1] >= x)++p;
            pre[i] = p;
        }
        for(int j = 1; j <= K; ++j){
            for(int i = 1; i <= N; ++i){
                f[i][j] = add(f[i][j] , sum[pre[i]][j - 1]);
                sum[i][j] = add(sum[i][j] , add(sum[i - 1][j] , f[i][j]));
            }
        }
        ll v = 0;
        for(int i = 1; i <= N; ++i){
            v = add(v , f[i][K]);
            ans = add(ans , f[i][K]);
        }
    }
    cout << ans << endl;
}       