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
        int N=read();
        vector<vector<int>>a(N+1,vector<int>(N+1));
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                a[i][j]=read();
            }
        }
        vector<vector<pii>>right_down;
        for(int i=N;i>=1;--i){
            vector<pii>vec;
            int r=1,c=i;
            while(r<=N&&c<=N){
                vec.push_back({r,c});
                ++r,++c;
            }
            right_down.push_back(vec);
        }
        for(int i=2;i<=N;++i){
            vector<pii>vec;
            int r=i,c=1;
            while(r<=N&&c<=N){
                vec.push_back({r,c});
                ++r,++c;
            }
            right_down.push_back(vec);
        }
        vector<vector<pii>>left_down;
        for(int i=1;i<=N;++i){
            vector<pii>vec;
            int r=1,c=i;
            while(r<=N&&c>=1){
                vec.push_back({r,c});
                ++r,--c;
            }
            left_down.push_back(vec);
        }
        for(int i=2;i<=N;++i){
            vector<pii>vec;
            int r=i,c=N;
            while(r<=N&&c>=1){
                vec.push_back({r,c});
                ++r,--c;
            }
            left_down.push_back(vec);
        }
        int ans=0;
        for(int i=0;i<left_down.size();i+=4){
            for(int j=0;j<left_down[i].size();j+=2){
                int r=left_down[i][j].x,c=left_down[i][j].y;
                ans^=a[r][c];
            }
        }
        for(int i=0;i<right_down.size();i+=4){
            for(int j=0;j<right_down[i].size();j+=2){
                int r=right_down[i][j].x,c=right_down[i][j].y;
                ans^=a[r][c];
            }
        }
        printf("%d\n",ans);
    }
}