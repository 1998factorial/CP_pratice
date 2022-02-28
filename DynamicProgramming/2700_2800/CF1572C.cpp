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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>a(N+1),b;
        for(int i=1;i<=N;++i)cin>>a[i];
        b.push_back(0);
        for(int i=1;i<=N;++i){
            if(a[i]!=a[i-1])b.push_back(a[i]);
        }
        N=b.size()-1;
        a=b;
        vector<vector<int>>pos(N+5),dp(N+5,vector<int>(N+5,N-1));
        for(int i=1;i<=N;++i)pos[a[i]].push_back(i);
        for(int i=1;i<=N;++i)dp[i][i]=0;
        for(int len=2;len<=N;++len){
            for(int i=1;i+len-1<=N;++i){
                int j=i+len-1;
                dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                for(int k:pos[a[i]]){
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]);
                }
            }
        }
        cout<<dp[1][N]<<endl;
    }
}