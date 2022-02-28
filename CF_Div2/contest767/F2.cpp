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
inline ll inverse(ll x){
    return qpow(x,mod-2);
}
ll gcd(ll n,ll m){
    return n==0?m:gcd(m%n,n);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}
ll f[maxv],inv[maxv],p[maxv],ip[maxv];
ll C(int n,int m){
    if(n<0||m<0||n<m)return 0;
    return mul(f[n],mul(inv[m],inv[n-m]));
}
int main(){
    f[0]=1;inv[0]=inverse(f[0]);
    for(int i=1;i<maxv;++i)f[i]=mul(f[i-1],i),inv[i]=inverse(f[i]);
    p[0]=1;ip[0]=inverse(p[0]);
    for(int i=1;i<maxv;++i)p[i]=mul(p[i-1],2),ip[i]=inverse(p[i]);
    int t=read();
    while(t--){
        int N=read(),M=read(),K=read();
        if(M==0){
            printf("0\n");
            continue;
        }
        if(N==M){
            printf("%lld\n",mul(K,N));
            continue;
        }
        ll ans=0;
        for(int i=1;i<=N;++i){
            ll v=C(N-i-1,M-i);
            v=mul(v,K);
            v=mul(v,i);
            v=mul(v,ip[N-i]);
            ans=add(ans,v);
        }
        printf("%lld\n",ans);
        /*vector<vector<ll>>dp(N+10,vector<ll>(N+10));
        dp[1][1]=1;
        for(int i=2;i<=N;++i){
            for(int j=1;j<i;++j){
                dp[i][j]=add(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                printf("%lld ",dp[i][j]);
            }
            printf("\n");
        }
        */
    }
}