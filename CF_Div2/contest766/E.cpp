#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(1)
#define DEBUG(x) std::cout << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 1e6 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18;
const int mod = 998244353;
int read(){
	bool minus=false;
	int result=0;
	char ch;
	ch=getchar();
	while(true){
		if(ch=='-')break;
		if(ch>='0'&&ch<='9')break;
		ch=getchar();
	}
	if(ch == '-')minus=true;
    else result=ch-'0';
	while(true){
		ch=getchar();
		if(ch<'0'||ch>'9')break;
		result=result*10+(ch-'0');
	}
	if(minus)
		return -result;
	else
		return result;
}
vector<pll>to[200055],room[100055];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M,K,cnt=0;
        N=read(),M=read(),K=read();
        vector<ll>X(N+50);
        for(int i=1;i<=N;++i)X[i]=read();
        vector<ll>dp(2*K+50,inf64);
        room[1].push_back({1ll,++cnt});
        dp[cnt]=0;
        for(int i=1;i<=K;++i){
            ll a,b,c,d,h;
            a=read(),b=read(),c=read(),d=read(),h=read();
            room[a].push_back({b,++cnt});
            to[cnt].push_back({cnt+1,h});
            room[c].push_back({d,++cnt});
        }
        room[N].push_back({(ll)M,++cnt});
        for(int i=1;i<=N;++i){
            sort(room[i].begin(),room[i].end());
            int sz=room[i].size();
            //go from left to right
            for(int j=1;j<sz;++j){
                int cur=room[i][j].y,pre=room[i][j-1].y;
                dp[cur]=min(dp[cur],dp[pre]+X[i]*(room[i][j].x-room[i][j-1].x));
            }
            //go from right to left
            for(int j=sz-2;j>=0;--j){
                int cur=room[i][j].y,pre=room[i][j+1].y;
                dp[cur]=min(dp[cur],dp[pre]+X[i]*(room[i][j+1].x-room[i][j].x));
            }
            for(int j=0;j<sz;++j){
                int cur=room[i][j].y;
            }
            for(int j=0;j<sz;++j){
                int cur=room[i][j].y;
                if(dp[cur]!=inf64){
                    for(auto e:to[cur]){
                        dp[e.x]=min(dp[e.x],dp[cur]-e.y);
                    }
                }
            }
        }
        if(dp[cnt]==inf64){
            printf("NO ESCAPE\n");
        }
        else{
            printf("%lld\n",dp[cnt]);
        }
        for(int i=1;i<=N+1;++i){
            room[i].clear();
        }
        for(int i=1;i<=2*K+10;++i){
            to[i].clear();
        }
    }
}   