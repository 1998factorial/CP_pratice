/*
    for permutations:
    say we know the length of a permutation , say it is x
    now we want to insert some number y into this permutation
    the key is that we only need to know the rank of y in the permutation
    eg. N = 4
    insert order , [1 , 1 , 1 , 1] <=> [1st small , 1st small , 1st small , 1st small]
    [1] , [2 , 1] , [3 , 2 , 1] , [4 , 3 , 2 , 1]
    insert order , [1 , 2 , 1 , 3] <=> [1st small , 2rd small , 1st small , 3rd small]
    [1] , [1 , 2] , [2 , 3 , 1] , [2 , 4 , 1 , 3]
    with this way we can cover all permutations
*/
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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
ll mod = 1e9 + 7;
ll fac[maxn];
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    x += y;
    if(x >= mod)x -= mod;
    return x;
}
ll sub(ll x , ll y){
    x -= y;
    if(x < 0)x += mod;
    return x;
}
ll qpow(ll x , ll n){
    ll ans = 1;
    while(n){
        if(n & 1)ans = mul(ans , x);
        x = mul(x , x);
        n /= 2;
    }
    return ans;
}
ll inverse(ll x){
    return qpow(x , mod - 2);
}
ll C(int n , int m){
    if(n < 0 || m < 0 || n < m)return 0;
    return mul(fac[n] , mul(inverse(fac[n - m]) , inverse(fac[m])));
}
ll dp[55][2555][3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // fac[0] = 1;
    // for(int i = 1; i < maxn; ++i)fac[i] = mul(fac[i - 1] , (ll)i);
    int N;
    cin >> N >> mod;
    // 0 => p = q
    // 1 => p < q
    // 2 => p > q
    int total = N * (N - 1) / 2;
    int base = total + 10;
    dp[0][base][0] = 1;
    for(int len = 1; len <= N; ++len){
        // backward
        // as if we append, we will change state of prefix, and our flag will fail
        for(int ninversion = -len * (len - 1) / 2; ninversion <= len * (len - 1) / 2; ++ninversion){
            for(int pre = 0; pre <= 2; ++pre){
                for(int p = 1; p <= len; ++p){
                    for(int q = 1; q <= len; ++q){
                        int inc = (p - 1) - (q - 1);
                        int cur = pre;
                        int inversion = ninversion + base;
                        if(p == q){
                            cur = pre;
                        }
                        else if(p < q){
                            cur = 1;
                        }
                        else{
                            cur = 2;
                        }
                        dp[len][inversion][cur] = add(dp[len][inversion][cur] , dp[len - 1][inversion - inc][pre]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int ninversion = 1; ninversion <= total; ++ninversion){
        ans = add(ans , dp[N][ninversion + base][1]);
    }
    cout << ans << endl;
}   