#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cout << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int dp[505][505],N,L,K,a[505],d[505];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>L>>K;
    for(int i=1;i<=N;++i)cin>>d[i];
    for(int i=1;i<=N;++i)cin>>a[i];
    ++N;
    d[N]=L;
    dp[1][0]=0;
    for(int i=2;i<=N;++i){
        for(int k=0;k<=K;++k){
            dp[i][k]=inf32;
            for(int j=i-1;j>=1;--j){
                if(k-(i-j)+1<0){
                    break;
                }
                dp[i][k]=min(dp[i][k],dp[j][k-(i-j)+1]+(d[i]-d[j])*a[j]);
            }
        }
    }
    int ans=inf32;
    for(int i=0;i<=K;++i){
        ans=min(ans,dp[N][i]);
    }
    cout<<ans<<endl;
}