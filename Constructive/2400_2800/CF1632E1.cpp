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
vector<int>g[3002];
int dep[3002],up[3002][13],tin[3002],tout[3002],timmer,dis[3002][3002],lim;
multiset<int>L[3002];
vector<pii>vec[3005];
int R[3002];
void get_dep(int v,int p,int d){
    tin[v]=++timmer;
    dep[v]=d;
    up[v][0]=p;
    for(int i=1;i<=lim;++i){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int nv:g[v]){
        if(nv==p)continue;
        get_dep(nv,v,d+1);
    }
    tout[v]=timmer;
}
bool isAncestor(int fa,int son){
    return tin[fa]<=tin[son]&&tout[fa]>=tin[son];
}
int LCA(int u,int v){
    if(isAncestor(u,v)){
        return u;
    }
    if(isAncestor(v,u)){
        return v;
    }
    for(int i=lim;i>=0;--i){
        if(!isAncestor(up[v][i],u)){
            v=up[v][i];
        }
    }
    return up[v][0];
}
int main(){
    int t=read(),i,j,x,N;
    while(t--){
        N=read();
        timmer=0;
        lim=ceil(log2(N));
        for(i=1;i<=N;++i)g[i].clear(),dep[i]=0;
        for(i=1;i<N;++i){
            int u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        get_dep(1,1,0);
        for(i=1;i<=N;++i){
            for(j=1;j<=N;++j){
                if(i==j)dis[i][j]=0;
                else{
                    dis[i][j]=dep[i]+dep[j]-2*dep[LCA(i,j)];
                }
            }
        }
        for(i=1;i<=N;++i)vec[i].clear(),L[i].clear(),R[i]=0;
        for(i=1;i<=N;++i){
            for(j=1;j<=N;++j){
                if(dis[1][j]-dis[i][j]<=0){
                    vec[1].push_back({i,j});
                }
                else{
                    vec[dis[1][j]-dis[i][j]].push_back({i,j});
                }
                L[i].insert(dis[i][j]);
            }
        }
        for(x=1;x<=N;++x){
            int ans=inf32;
            for(pii&e:vec[x]){
                int i=e.x,j=e.y;
                auto it=L[i].find(dis[i][j]);
                if(it!=L[i].end()){
                    L[i].erase(it);
                    if(R[i]<dis[1][j]){
                        R[i]=dis[1][j];
                    }
                }
            }
            for(i=1;i<=N;++i){
                int max_val=0;
                if(!L[i].empty()){
                    int value=*(L[i].rbegin())+x;
                    if(max_val<value){
                        max_val=value;
                    }
                }
                if(max_val<R[i]){
                    max_val=R[i];
                }
                if(ans>max_val){
                    ans=max_val;
                }
            }
            printf("%d ",ans);
        }
    }
}   