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
const ll mod = 998244353;
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll mul(ll x , ll y){
    return x * y % mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N);
        vector<vector<int>> pos(N + 10 , vector<int>());
        vector<vector<vector<ll>>> dp(N + 10 , vector<vector<ll>> (2 , vector<ll>(2 , 0)));
        // dp[i][j][k] = the number of good subsequences if the sequence ends with
        // a[i] and 
        // for j
        // 0 -> mex = a[i] - 1
        // 1 -> mex = a[i] + 1
        // for k
        // 0 -> we have not selected mex + 1
        // 1 -> we have selected mex + 1
        for(int i = 0; i < N; ++i)cin >> a[i];
        ll ans = 0;
        for(int i = 0; i < N; ++i){
            int v = a[i];
            vector<vector<ll>> tmp(2 , vector<ll>(2));
            if(v == 0){
                tmp[1][0] = add(tmp[1][0] , 1);
            }
            if(v == 1){
                tmp[0][1] = add(tmp[0][1] , 1);
            }
            for(int d = -2; d <= 2; ++d){
                int pv = v + d;
                if(pv < 0)continue;
                for(int x : {0 , 1}){
                    for(int y : {0 , 1}){
                        int mex , nmex;
                        if(x == 0)mex = pv - 1;
                        else mex = pv + 1;
                        nmex = mex;
                        if(v == mex){
                            if(y)nmex += 2;
                            else nmex += 1;
                        }
                        if(abs(v - nmex) > 1)continue;
                        int nx = nmex == v + 1;
                        int ny = (v == nmex + 1) || (nmex == mex && y);
                        tmp[nx][ny] = add(tmp[nx][ny] , dp[pv][x][y]);
                        debug printf("tmp[%d][%d] += (dp[%d][%d][%d]=%lld)\n" ,nx,ny,v,x,y,dp[pv][x][y]);
                    }
                }
            }
            debug cout << "at i = " << i << endl;
            for(int x : {0 , 1}){
                for(int y : {0 , 1}){
                    dp[v][x][y] = add(dp[v][x][y] , tmp[x][y]);
                    debug printf("dp[%d][%d][%d]=%lld\n",v,x,y,dp[v][x][y]);
                }
            }
        }
        for(int v = 0; v <= N; ++v){
            for(int x : {0 , 1})for(int y : {0 , 1}){
                ans = add(ans , dp[v][x][y]);
            }
        }
        cout << ans << endl;
    }
}