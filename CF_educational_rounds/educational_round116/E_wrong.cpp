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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const ll mod = 998244353;
ll C[505][505] , dp[505];
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll mul(ll x , ll y){
    return x * y % mod;
}
inline ll qpow(ll x , ll n){
    ll ret = 1ll;
    while(n){
        if(n % 2)ret = mul(ret , x);
        x = mul(x , x);
        n >>= 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , X;
    cin >> N >> X;
    C[0][0] = 1;
    for(int i = 1; i <= 500; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i){
                C[i][j] = 1;
            }
            else{
                C[i][j] = add(C[i - 1][j] , C[i - 1][j - 1]);
            }
        }
    }
    ll ans = 0;
    for(int v = 1; v <= N - 1; ++v){
        dp[v] = mul(qpow(v - 1 , N - 1) , C[N][1]);
        //printf("dp[%d] = %lld\n" , v , dp[v]);
        for(int nv = v; nv <= X; nv += N - 1){
            ans = add(ans , dp[v]);
        }
    }
    for(int v = 1; v <= X; ++v){
        //printf("for v = %d\n" , v);
        for(int i = 2; i <= N; ++i){
            //printf("+= C[%d][%d] * (%d)^%d\n" , N , i , v - 1 , N - i);
            ans = add(ans , mul(C[N][i] , qpow((ll)v - 1 , N - i)));
        }
    }
    cout << ans << endl;
}