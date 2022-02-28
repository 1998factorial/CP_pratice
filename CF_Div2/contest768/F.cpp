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
int main(){
    int t=read();
    while(t--){
		int N=read(),M=read();
        vector<ll>a(N+1);
        for(int i=0;i<N;++i)a[i]=read();
        vector<int>b(M+1);
        for(int i=1;i<=M;++i)b[i]=read();
        int d=0;
        for(int i=1;i<=M;++i)d=gcd(d,b[i]);
        if(d==1){
            ll ans=0;
            for(int i=0;i<N;++i)ans+=abs(a[i]);
            printf("%lld\n",ans);
            continue;
        }
        vector<vector<ll>>dp(d,vector<ll>(2));
        for(int i=0;i<min(d,N);++i){
            dp[i][0]=a[i];
            dp[i][1]=-a[i];
        }
        for(int i=d;i<N;++i){
            ll v0=dp[i%d][0],v1=dp[i%d][1];
            dp[i%d][0]=max(v0+a[i],v1-a[i]);
            dp[i%d][1]=max(v1+a[i],v0-a[i]);
        }
        ll ans=-inf64;
        for(int j=0;j<2;++j){
            ll sum=0;
            for(int i=0;i<d;++i){
                sum+=dp[i][j];
            }
            ans=max(ans,sum);
        }
        printf("%lld\n",ans);
    }
}