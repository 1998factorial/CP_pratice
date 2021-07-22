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
const ll mod = 998244353;
ll f[maxn];
ll mul(ll x , ll y){
    return x * y % mod;
}
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll sub(ll x , ll y){
    return ((x - y) % mod + mod) % mod;
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
    return mul(f[n] , mul(inverse(f[n - m]) , inverse(f[m])));
}
int N , base , a[505];
ll p[505];
ll solve(int mid){
    //-1 , +1 , +2 , -1
    ll ans = p[N - 1];
    vector<ll> dp(N + 5);
    dp[0] = 1;
    for(int i = 1; i < mid; ++i){
        vector<ll> ndp(N + 5);
        if(a[i] == -1){
            for(int j = 0; j <= N; ++j){
                ndp[j] = add(ndp[j] , dp[j]); // do not choose
                ndp[j] = add(ndp[j] , dp[j + 1]); // choose
                if(j == 0)ndp[j] = add(ndp[j] , dp[j]); // choose for j = 0
            }
        }
        else if(a[i] <= a[mid]){
            for(int j = 0; j <= N; ++j){
                ndp[j] = add(ndp[j] , dp[j]); // do not choose
                if(j - 1 >= 0)ndp[j] = add(ndp[j] , dp[j - 1]); // one more
            }
        }
        else{
            for(int j = 0; j <= N; ++j){
                ndp[j] = mul(dp[j] , 2ll);
            }
        }
        dp = ndp;
    }
    ll bad = 0; // the number of bad subsequences
    for(int i = mid + 1; i <= N; ++i){
        bad = add(bad , bad); 
        // for each bad subsequences , either we take a[i] or not, still considered as bad
        vector<ll> ndp(N + 5);
        if(a[i] == -1){
            bad = add(bad , dp[0]);
            for(int j = 0; j <= N; ++j){
                ndp[j] = add(ndp[j] , dp[j]); // do not take it
                ndp[j] = add(ndp[j] , dp[j + 1]); // take it
            }
        }
        else if(a[i] < a[mid]){
            // avoid overcount values = a[mid]
            for(int j = 0; j <= N; ++j){
                ndp[j] = add(ndp[j] , dp[j]); // do not choose
                if(j - 1 >= 0)ndp[j] = add(ndp[j] , dp[j - 1]); // one more
            }
        }
        else{
            // if we get a[i] = a[mid] , later we get to state dp[0] , we erase a[mid]
            for(int j = 0; j <= N; ++j){
                ndp[j] = mul(dp[j] , 2ll);
            }
        }
        dp = ndp;
    }
    ans = sub(ans , bad);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        char op;
        cin >> op;
        if(op == '+'){
            int x;
            cin >> x;
            a[i] = x;
        }
        else{
            a[i] = -1;
        }
    }
    f[0] = 1;
    for(int i = 1; i < maxn; ++i){
        f[i] = mul(f[i - 1] , i);
    }
    p[0] = 1;
    for(int i = 1; i < 505; ++i){
        p[i] = mul(p[i - 1] , 2);
    }
    ll ans = 0;
    base = N + 5;
    // [#(<= a[i]) - #(-) = x]... a[i] ... []
    for(int i = 1; i <= N; ++i){
        // consider contribution for a[i]
        if(a[i] == -1)continue;
        ans = add(ans , mul(a[i] , solve(i)));
    }
    cout << ans << endl;
}