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
}   