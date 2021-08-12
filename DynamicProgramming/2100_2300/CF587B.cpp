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
const int mod = 1e9 + 7;
ll add(ll x , ll y){
    x %= mod;
    y %= mod;
    ll ans = x + y;
    return ans % mod;
}
ll mul(ll x , ll y){
    x %= mod;
    y %= mod;
    ll ans = x * y;
    return ans % mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N , L , K;
    cin >> N >> L >> K;
    vector<ll> a(N) , p(N) , ip(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        p[i] = i;
    }
    sort(p.begin() , p.end() , [&](ll& l , ll& r){
        return a[l] < a[r];
    });
    for(int i = 0; i < N; ++i){
        ip[p[i]] = i;
    }
    vector<vector<ll>> dp(K + 1 , vector<ll>(N + 1 , 0));
    for(int i = 0; i < N; ++i)dp[1][i] = 1;
    for(int j = 2; j <= K; ++j){
        ll sum = 0;
        int k = 0;
        for(int i = 0; i < N; ++i){
            while(k < N && a[p[k]] <= a[p[i]]){
                sum = add(sum , dp[j - 1][k]);
                ++k;
            }
            dp[j][i] = add(dp[j][i] , sum);
        }
    }
    int ans = 0;
    ll C = L / N;
    ll T = L % N;
    for(int i = 0; i < N; ++i){
        int x = ip[i];
        if(i < T){
            ll up = min(K , C + 1);
            for(int j = 1; j <= up; ++j){
                ans = add(ans , mul(C + 1 - j + 1 , dp[j][x]));
            }
        }
        else{
            ll up = min(K , C);
            for(int j = 1; j <= up; ++j){
                ans = add(ans , mul(C - j + 1 , dp[j][x]));
            }
        }
    } 
    cout << ans << endl;
} 
// solve it bucket by bucket (each bucket is N)
// once fixed a bucket, the rest is done