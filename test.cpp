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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<ll> a(N + 1) , b(N + 1) , id(N);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    sort(a.begin() + 1 , a.end());
    for(int i = 1; i <= N; ++i){
        b[i] = a[N] - a[i]; 
        id[i] = i + 1;
    }    
    vector<vector<ll>> dp(65 , vector<ll>(N + 1 , inf64));
    // for 0th bit
    for(int k = 0; k < 2; ++k){
        dp[0][k] = 0;
        for(int j = 1; j <= N; ++j){
            int v = (b[j] & (1 << 0)) ? 1 : 0;
            dp[0][k] += (k + (b[j])) % 2;
        }
    }
    for(int i = 1; i < 65; ++i){
        ll mod = 1LL << i;
        sort(id.begin() , id.end() , [&](int& l , int& r){
            return (b[l] % mod) < (b[r] % mod);
        });
        vector<int> sum(N + 1);
        for(int j : id){
            int v = (b[j] & (1 << i)) ? 1 : 0;
            sum[j] += v;
        }
        for(int j = 1; j <= N; ++j)sum[j] += sum[j - 1];
        // we now enumerate the number of carries we have
        for(int nc = 0; nc <= N; ++nc){
            // enumerate the ith bit of t
            for(int k = 0; k < 2; ++k){

            }
        }
    }
    cout << min(dp[64][0] , dp[64][1]) << endl;
}   