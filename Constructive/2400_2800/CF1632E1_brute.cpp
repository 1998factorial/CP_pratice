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
const ll mod=1e9+7;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
ll read(){
	bool minus=false;
	ll result=0;
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
inline ll add(ll x,ll y){
    return ((x+y)%mod+mod)%mod;
}
inline ll mul(ll x,ll y){
    return x*y%mod;
}
inline ll qpow(ll x,ll n){
    ll ret=1ll;
    while(n){
        if(n&1)ret=mul(ret,x);
        x=mul(x,x);
        n>>=1;
    }
    return ret;
}
ll gcd(ll n,ll m){
    return n==0?m:gcd(m%n,n);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}
vector<pii>g[3005];
int depth[3005],dp[3005],vis[3005];
void get_depth(int v,int p,int d){
    depth[v]=d;
    for(auto&e:g[v]){
        if(e.x==p)continue;
        get_depth(e.x,v,d+e.y);
    }
}
int main(){
    int t=read();
    while(t--){
        int N=read();
        for(int i=1;i<=N;++i)g[i].clear(),depth[i]=0;
        for(int i=1;i<N;++i){
            int u=read(),v=read();
            g[u].push_back({v,1});
            g[v].push_back({u,1});
        }
        get_depth(1,1,0);
        for(int x=1;x<=N;++x){
            //printf("for x = %d\n",x);
            int val=inf32;
            int bu=-1,bv=-1;
            for(int u=1;u<=1;++u){
                for(int v=1;v<=N;++v){
                    g[u].push_back({v,x});
                    g[v].push_back({u,x});
                    int value_here=0;
                    for(int i=1;i<=N;++i)dp[i]=inf32,vis[i]=0;
                    dp[1]=0;
                    priority_queue<pii,vector<pii>,greater<pii>>q;
                    q.push({dp[1],1});
                    while(!q.empty()){
                        pii cur=q.top();
                        q.pop();
                        int v=cur.y,d=cur.x;
                        if(vis[v])continue;
                        vis[v]=1;
                        for(auto&e:g[v]){
                            int nv=e.x,w=e.y;
                            if(vis[nv])continue;
                            if(dp[nv]>d+w){
                                dp[nv]=d+w;
                                q.push({dp[nv],nv});
                            }
                        }
                    }
                    for(int i=1;i<=N;++i){
                        value_here=max(value_here,dp[i]);
                    }
                    if(val>value_here){
                        val=value_here;
                        bu=u,bv=v;
                    }
                    val=min(val,value_here);
                    //printf("add (%d %d)\n",u,v);
                    //printf("val = %d\n",val);
                    g[u].pop_back();
                    g[v].pop_back();
                }
            }
            printf("%d ",val);
            //printf("x = %d    val = %d ",x,val);
            //printf("best edge (%d %d)\n",bu,bv);
        }
        printf("\n");
    }
}   