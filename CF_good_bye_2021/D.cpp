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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>a(N+1,0);
        for(int i=1;i<=N;++i)cin>>a[i];
        int X;
        cin>>X;
        for(int i=1;i<=N;++i)a[i]-=X;
        if(N<=1){
            cout<<1<<endl;
            continue;
        }
        if(N<=2){
            if(a[1]+a[2]<0)cout<<1<<endl;
            else cout<<2<<endl;
            continue;
        }
        //we need to choose some a[i] st all contigious segments length>=2 are non-negative
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(2,0)));
        int ans=0;
        dp[1][0][0]=0;
        dp[1][0][1]=1;
        for(int i=1;i<N;++i){
            for(int x=0;x<2;++x){
                for(int y=0;y<2;++y){
                    if(y){
                        if(x&&a[i+1]+a[i]>=0&&a[i+1]+a[i]+a[i-1]>=0){
                            dp[i+1][y][1]=max(dp[i+1][y][1],dp[i][x][y]+1);
                        }
                        if(!x&&a[i+1]+a[i]>=0){
                            dp[i+1][y][1]=max(dp[i+1][y][1],dp[i][x][y]+1);
                        }
                        dp[i+1][y][0]=max(dp[i+1][y][0],dp[i][x][y]);
                    }
                    else{
                        dp[i+1][y][0]=max(dp[i+1][y][0],dp[i][x][y]);
                        dp[i+1][y][1]=max(dp[i+1][y][1],dp[i][x][y]+1);
                    }
                }
            }
        }
        for(int i=1;i<=N;++i){
            for(int x=0;x<2;++x){
                for(int y=0;y<2;++y){
                    ans=max(ans,dp[i][x][y]);
                }
            }
        }
        cout<<ans<<endl;
    }
}