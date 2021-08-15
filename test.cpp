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
int add(int x , int y){
    ll ans = x;
    ans += y;
    while(ans >= mod)ans -= mod;
    return ans;
}
int mul(int x , int y){
    ll ans = x;
    ans *= y;
    return ans % mod;
}
int N , a[505][505] , f[505][505] , g[505][505];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)cin >> a[i][j];
    for(int i = 1; i <= N; ++i)f[i][i] = g[i][i] = 1;
    for(int len = 2; len <= N; ++len){
        for(int i = 1; i + len - 1 <= N; ++i){
            int j = i + len - 1;
            if(a[i][j])
                for(int k = i; k < j; ++k){
                    g[i][j] = add(g[i][j] , mul(f[i][k] , f[k + 1][j]));
                }
            for(int k = i + 1; k <= j; ++k){
                if(a[i][k])
                    f[i][j] = add(f[i][j] , mul(g[i][k] , f[k][j]));
            }
        }
    }
    cout << f[1][N] << endl;
}   