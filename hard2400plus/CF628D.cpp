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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int add(int x , int y){
    ll ans = (ll)x + y;
    if(ans >= mod)ans -= mod;
    return ans;
}
int mul(int x , int y){
    ll ans = (ll)x * y;
    return ans % mod;
}
int dp[2005][2005][2][2] , M , N , D;
char a[2005] , b[2005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> D;
    cin >> (a + 1);
    cin >> (b + 1);
    N = strlen(a + 1);
    dp[0][0][1][1] = 1;
    // dp[pos][mod][p][q]
    // p => x == a
    // !p => x > a
    // q => x == b
    // !q => x < b
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            for(int p = 0; p < 2; ++p){
                for(int q = 0; q < 2; ++q){
                    if(dp[i][j][p][q] == 0)continue;
                    vector<int> digits;
                    if((i + 1) & 1){
                        for(int k = 0; k <= 9; ++k){
                            if(k != D)digits.push_back(k);
                        }
                    }
                    else{
                        digits.push_back(D);
                    }
                    int av = a[i + 1] - '0';
                    int bv = b[i + 1] - '0';
                    for(int d : digits){
                        if(p && d < av)continue;
                        if(q && d > bv)continue;
                        int np = p && (d == av);
                        int nq = q && (d == bv);
                        int nj = (j * 10 + d) % M;
                        int ni = i + 1;
                        dp[ni][nj][np][nq] = add(dp[ni][nj][np][nq] , dp[i][j][p][q]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            ans = add(ans , dp[N][0][i][j]);
        }
    }
    cout << ans << endl;
}       