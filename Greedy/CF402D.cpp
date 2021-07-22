#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
map<int , int> bad;
map<int , int> dp;
int gcd(int n , int m){
    return n == 0 ? m : gcd(m % n , n);
}
int f(int x){
    if(dp.find(x) != dp.end())return dp[x];
    int ans = 0;
    int xx = x;
    for(ll i = 2; i * i <= x; ++i){
        while(x % i == 0){
            if(bad[i])--ans;
            else ++ans;
            x /= i;
        }
    }
    if(x > 1){
        if(bad[x])--ans;
        else ++ans;
    }
    dp[xx] = ans;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , M;
    cin >> N >> M;
    vector<int> a(N + 1) , prefix(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= M; ++i){
        int x;
        cin >> x;
        bad[x]++;
    }
    int ans = 0;
    prefix[1] = a[1];
    for(int i = 2; i <= N; ++i){
        prefix[i] = gcd(prefix[i - 1] , a[i]);
    }
    for(int i = N; i >= 1; --i){
        int d = prefix[i];
        int v = f(d);
        if(v < 0){
            for(int j = 1; j <= i; ++j){
                a[j] /= d;
                prefix[j] /= d;
            }
        }
        //printf("f[%d] = %d\n" , a[i] , f(a[i]));
        ans += f(a[i]);
    }
    cout << ans << endl;
}