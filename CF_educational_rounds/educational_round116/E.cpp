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
ll C[505][505] , dp[505][505];
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
    // dp[i][j] = # of ways so that we have i alive people 
    // and each of them takes j dmg so far
    dp[N][0] = 1;
    for(int i = N; i >= 1; --i){
        for(int j = 0; j <= X; ++j){
            for(int ni = i; ni >= 0; --ni){
                int nj = min(X , j + i - 1); // we might go over X 
                if((nj < X) || (nj == X && ni == 0)){
                    dp[ni][nj] = add(dp[ni][nj] , mul(mul(dp[i][j] , qpow(nj - j , i - ni)) , C[i][ni]));
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= X; ++i)ans = add(ans , dp[0][i]);
    cout << ans << endl;
}