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
const int maxn = 305;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const int mod = 1e9 + 7;
int add(int x , int y){
    ll ans = x;
    ans += y;
    if(ans >= mod)ans -= mod;
    return ans;
}
int mul(int x , int y){
    return (ll)x * y % mod;
}
int a[maxn] , fa[maxn] , M , N , t[maxn] , sz[maxn];
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int x , int y){
    x = find(x);
    y = find(y);
    if(x != y){
        fa[x] = y;
    }
}
int g[maxn][maxn] , dp[maxn][maxn] , C[maxn][maxn] , F[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i] , fa[i] = i;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            ll v = (ll)a[i] * a[j];
            ll vv = sqrt(v);
            if(vv * vv == v){
                unite(i , j);
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        ++t[find(i)];
    }
    M = 0;
    for(int i = 1; i <= N; ++i){
        if(t[i]){
            ++M;
            sz[M] = t[i];
        }
    }
    g[0][0] = 1;
    C[0][0] = 1;
    F[0] = 1;
    // g[i][j] = the number of ways to divide i elements
    // into j non empty groups , where ordering matters within 
    // each group (but group-wise ordering doesn't matter)
    for(int i = 1; i <= N; ++i){
        F[i] = mul(F[i - 1] , i);
        for(int j = 1; j <= i; ++j){
            g[i][j] = add(g[i][j] , g[i - 1][j - 1]);
            g[i][j] = add(g[i][j] , mul(g[i - 1][j] , i + j - 1)); 
        }
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = add(C[i - 1][j] , C[i - 1][j - 1]);
            }
        }
    }
    int prefix = 0;
    dp[0][0] = 1;
    // O(sum{M * N * sz[i]}) ~ O(N^3)
    for(int i = 0; i < M; ++i){
        for(int j = 0; j <= prefix; ++j){
            for(int x = 1; x <= sz[i + 1]; ++x){ // split into x groups
                for(int y = 0; y <= min(j , x); ++y){ // break y bad pairs
                    int nj = j + sz[i + 1] - x - y;
                    int val = g[sz[i + 1]][x]; // # of ways to split sz[i + 1] elements into x groups
                    val = mul(val , C[x][y]); // among x groups, select y ones to break bad pairs
                    val = mul(val , C[j][y]); // among j bad pairs, select y ones to break
                    val = mul(val , F[y]); // these y groups can be permuted freely once fixed position
                    val = mul(val , C[prefix + 1 - j][x - y]); // we have prefix + 1 - j spots to put the rest x - y groups
                    val = mul(val , F[x - y]); // we can permute these x - y groups freely
                    dp[i + 1][nj] = add(dp[i + 1][nj] , mul(val , dp[i][j]));
                }
            }
        }
        prefix += sz[i + 1];
    }
    cout << dp[M][0] << endl;
}   
