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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N,M,K;
        cin>>N>>M>>K;
        vector<ll>X(N+5),H(K+5);
        for(int i=1;i<=N;++i)cin>>X[i];
        vector<pii>to[N+5];
        vector<array<ll,5>>ladders;
        ladders.push_back({1,1,1,1,0});
        to[1].push_back({1,0});
        for(int j=1;j<=K;++j){
            ll a,b,c,d;
            cin>>a>>b>>c>>d>>H[j];
            ladders.push_back({a,b,c,d,H[j]});
            to[c].push_back({d,j});
        }
        ladders.push_back({N,M,N+1,M,0});
        to[N+1].push_back({M,K+1});
        vector<ll>dp(K+5,inf64); 
        // dp[i]=minimal health loss if we are at the end point of ladder[i]
        dp[0]=0;
        vector<int>id(K+2);
        for(int i=0;i<=K+1;++i)id[i]=i;
        sort(id.begin(),id.end(),[&](int&l,int&r){
            return ladders[l][0]<ladders[r][0];
        });
        for(int i:id){
            if(i==0)continue;
            ll a=ladders[i][0],b=ladders[i][1],HP=ladders[i][4];//from coordinate
            for(auto&e:to[a]){
                ll col=e.x,ni=e.y;  
                ll dis=(ll)abs(b-col)*X[a];
                if(dp[ni]>=inf64)continue;
                dp[i]=min(dp[i],dp[ni]+dis-HP);
            }
            printf("dp[%d]=%lld\n",i,dp[i]);
        }
        if(dp[K+1]>=inf64){
            cout<<"NO ESCAPE\n";
        }
        else{
            cout<<dp[K+1]<<endl;
        }
    }
}   