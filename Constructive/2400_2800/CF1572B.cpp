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
        int N=read(),cnt=0;
        vector<int>a(N+1);
        for(int i=1;i<=N;++i){
            a[i]=read();
            cnt+=a[i];
        }
        if(cnt&1){
            printf("NO\n");
            continue;
        }
        if(N&1){
            vector<int>ans;
            for(int i=1;i<=N-2;i+=2){
                ans.push_back(i);
            }
            for(int i=N-4;i>=1;i-=2){
                ans.push_back(i);
            }
            printf("YES\n%d\n",(int)ans.size());
            for(int i:ans)printf("%d ",i);
            printf("\n");
        }
        else{
            int prefix=0;
            vector<int>ps(N+1);
            for(int i=1;i<=N;++i){
                ps[i]=ps[i-1]+a[i];
            }
            for(int i=1;i<N;i+=2){
                if((ps[i]&1)==0){
                    prefix=i;
                    break;
                }
            }
            if(prefix==0){
                printf("NO\n");
                continue;
            }
            vector<int>ans;
            for(int i=1;i<=prefix-2;i+=2){
                ans.push_back(i);
            }
            for(int i=prefix-4;i>=1;i-=2){
                ans.push_back(i);
            }
            for(int i=prefix+1;i<=N-2;i+=2){
                ans.push_back(i);
            }
            for(int i=N-4;i>=prefix+1;i-=2){
                ans.push_back(i);
            }
            printf("YES\n%d\n",(int)ans.size());
            for(int i:ans)printf("%d ",i);
            printf("\n");

        }
    }
}