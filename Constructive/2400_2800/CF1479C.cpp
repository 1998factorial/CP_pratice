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
    int L=read(),R=read(),N=23;
    vector<array<int,3>>ans;
    for(int i=2;i<=N;++i){
        ans.push_back({1,i,L});
    }
    for(int i=2;i<=21;++i){
        for(int j=i+1;j<=22;++j){
            ans.push_back({i,j,(1<<(i-2))});
        }
    }
    int d=R-L;
    for(int i=22;i>=2;--i){
        if(d>>(i-2)&1){
            d-=1<<(i-2);
            //[L+d+1,L+d+2^(i-2)]
            ans.push_back({i,N,d+1});
        }
    }
    printf("YES\n%d %d\n",N,(int)ans.size());
    for(auto e:ans){
        printf("%d %d %d\n",e[0],e[1],e[2]);
    }
}