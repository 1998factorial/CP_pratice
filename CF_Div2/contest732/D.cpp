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
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 998244353; 
/*
    This problem is tricky https://codeforces.com/contest/1546/problem/D
*/
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
void init(){
    fac[0] = 1;
    for(int i = 1; i < maxn; ++i)fac[i] = mul(fac[i - 1] , (ll)i);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int t;
    cin >> t;
    for(int i = 1; i <= 20; ++i){
        for(int j = 0; j <= i; ++j){
            //if(C(i , j) == 715)cout << i << " " << j<<endl;
        }
    }
    while(t--){
        int N;
        cin >> N;
        string a;
        cin >> a;
        int adj_pair = 0;
        int pre = -1;
        int nzero = 0;
        // number of distinct adjcent pair of ones does not change
        // 011011 -> 2
        // 110011 -> 2
        // 00[11]0[11]0100[11]0[11][11]01 -> 5
        // 000[11][11]0100[11]00[11][11]1 -> 5
        // also the single 1s between any two 11s can not move arbitarily
        // so we are only interested in how the number of zeros changes
        // between each 11s
        for(int i = 0; i < N; ++i){
            if(a[i] == '1'){
                if(i - 1 >= 0 && a[i - 1] == '1' && pre < i - 1){
                    ++adj_pair;
                    pre = i;
                }
            }
            else ++nzero;
        }
        //cout << "adj_pair = " << adj_pair << endl;
        cout << C(adj_pair + nzero , nzero) << endl;
    }
}   
