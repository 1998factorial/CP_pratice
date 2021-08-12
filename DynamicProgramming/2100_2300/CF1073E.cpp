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
const int inf32 = 1e9;
const ll inf64 = 1e18;
const int mod = 998244353;
const int limit = (1 << 10) - 1;
ll L , R , K;
int add(int x , int y){
    ll ans = x;
    ans += y;
    if(ans >= mod)ans -= mod;
    return ans;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
vector<int> to_base_ten(ll x){
    vector<int> ans;
    while(x){
        ans.push_back(x % 10);
        x /= 10;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
int dp[20][limit + 10][2][2][2] , f[20][limit + 10][2][2][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> L >> R >> K;
    vector<int> a = to_base_ten(L);
    vector<int> b = to_base_ten(R);
    while(a.size() < b.size()){
        a.insert(a.begin() , 0);
    }  
    // dp[i][j][p][q][t] => sums
    // f[i][j][p][q][t] => ways
    // !p => x > a
    // p => x == a
    // !q => x < b
    // q => x == b
    // t => leading zeros
    // !t => no leading zero anymore
    int N = a.size();
    memset(dp , 0 , sizeof(dp));
    memset(f , 0 , sizeof(f));
    f[0][0][1][1][1] = 1;
    for(int i = 0; i < N; ++i){
        for(int mask = 0; mask <= limit; ++mask){
            for(int p = 0; p < 2; ++p){
                for(int q = 0; q < 2; ++q){
                    for(int t = 0; t < 2; ++t){
                        if(f[i][mask][p][q][t] == 0)continue;
                        int av = a[i] , bv = b[i];
                        for(int d = 0; d < 10; ++d){
                            if(p && d < av)continue;
                            if(q && d > bv)continue;
                            int np = p && (d == av);
                            int nq = q && (d == bv);
                            int nmask = mask;
                            if(d > 0)nmask |= (1 << d);
                            if(d == 0 && t == 0)nmask |= (1 << d);
                            int ni = i + 1;
                            int nt = t && (d == 0);
                            if(__builtin_popcount(nmask) > K)continue;
                            int val = add(mul(dp[i][mask][p][q][t] , 10) , mul(d , f[i][mask][p][q][t]));
                            f[ni][nmask][np][nq][nt] = add(f[ni][nmask][np][nq][nt] , f[i][mask][p][q][t]);
                            dp[ni][nmask][np][nq][nt] = add(dp[ni][nmask][np][nq][nt] , val);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int t = 0; t < 2; ++t){
                for(int mask = 0; mask <= limit; ++mask){
                    if(__builtin_popcount(mask) <= K){
                        ans = add(ans , dp[N][mask][i][j][t]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}   
