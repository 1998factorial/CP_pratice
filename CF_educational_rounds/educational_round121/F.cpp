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
const ll mod=998244353;
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
ll M,N,a0,x,y,K;
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
int main(){
    N=read();
    a0=read();
    x=read();
    y=read();
    K=read();
    M=read();
    ll up=1;
    for(int i=1;i<=K;++i){
        up=lcm(up,i);
    }
    vector<ll>cnt(up+10);
    ll ans=0,sum=0,P=qpow(N,mod-2);
    for(int i=0;i<N;++i,a0=(a0*x+y)%M){
        ++cnt[a0%up];
        sum=add(sum,a0);
    }
    for(int i=1;i<=K;++i){
        ans=add(ans,mul(sum,P));
        for(int v=1;v<up;++v){
            if(cnt[v]<=0)continue;
            ll dec=mul(P,mul(cnt[v],v%i));
            ll d=mul(P,cnt[v]);
            ll nv=v-v%i;
            cnt[v]=add(cnt[v],-d);
            cnt[nv]=add(cnt[nv],d); 
            sum=add(sum,-dec);
        }
    }
    ans=mul(ans,qpow(N,K));
    printf("%lld\n",ans);
}