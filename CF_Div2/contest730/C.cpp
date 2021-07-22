#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
#define ld long double
const ld EPS = 1e-7;
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
ld solve(ld c , ld m , ld p , ld v){
    ld ans = p;
    if(c > EPS){
        if(c > v - EPS){
            if(m > EPS){
                ans += (solve(c - v , m + v / 2 , p + v / 2 , v) + 1.0) * c;
            }
            else{
                ans += (solve(c - v , m , p + v , v) + 1.0) * c;
            }
        }
        else{
            if(m > EPS){
                ans += (solve(0 , m + c / 2 , p + c / 2 , v) + 1.0) * c;
            }
            else{
                ans += (solve(0 , m , p + c , v) + 1.0) * c;
            }
        }
    }
    if(m > EPS){
        if(m > v - EPS){
            if(c > EPS){
                ans += (solve(c + v / 2 , m - v , p + v / 2 , v) + 1.0) * m;
            }
            else{
                ans += (solve(c , m - v , p + v , v) + 1.0) * m;
            }
        }
        else{
            if(c > EPS){
                ans += (solve(c + m / 2 , 0 , p + m / 2 , v) + 1.0) * m;
            }
            else{
                ans += (solve(c , 0 , p + m , v) + 1.0) * m;
            }
        }
    }
    return ans;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    scanf("%d" , &t);
    while(t--){
        ld c , m , p , v;
        scanf("%Lf %Lf %Lf %Lf" , &c , &m , &p , &v);
        printf("%.10Lf\n" , solve(c , m , p , v));
    }
}   