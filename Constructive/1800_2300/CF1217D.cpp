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
int N,M,col[5005],back_edge,ecol[5005];
vector<pii>g[5005];
void DFS(int v){
    if(col[v]==0)col[v]=1;
    for(const auto&e:g[v]){
        int nv=e.x,eid=e.y;
        if(col[nv]==0){
            ecol[eid]=1;
            DFS(nv);
        }
        if(col[nv]==1){
            back_edge=1;
            ecol[eid]=2;
        }
        if(col[nv]==2){
            ecol[eid]=1;
        }
    }
    col[v]=2;
}
int main(){
    N=read();
    M=read();
    back_edge=0;
    for(int i=1;i<=M;++i){
        int u=read(),v=read();
        g[u].push_back({v,i});
    }
    for(int i=1;i<=N;++i){
        if(col[i]==0){
            DFS(i);
        }
    }
    int k=1+back_edge;
    printf("%d\n",k);
    for(int i=1;i<=M;++i){
        printf("%d ",ecol[i]);
    }
    printf("\n");
}   