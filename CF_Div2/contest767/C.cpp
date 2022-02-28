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
int N;
int tree[200005*4];
void update(int pos,int v){
    while(pos<=N){
        tree[pos]+=v;
        pos+=pos&(-pos);
    }
}
int ask(int pos){
    int ret=0;
    while(pos){
        ret+=tree[pos];
        pos-=pos&(-pos);
    }
    return ret;
}
int main(){
    int t;
    t=read();
    while(t--){
        N=read();
        for(int i=0;i<=4*N;++i)tree[i]=0;
        vector<int>a(N);
        map<int,int>cnt;
        for(int i=0;i<N;++i){
            a[i]=read();
            ++cnt[a[i]];
            if(cnt[a[i]]==1){
                update(a[i]+1,1);
            }
        }
        //compute mex of whole array
        int mex=0;
        for(;;++mex){
            if(cnt[mex]==0)break;
        }
        vector<int>ans;
        int k=0;
        while(k<N){
            set<int>v;
            for(;k<N;++k){
                if(a[k]<mex){
                    v.insert(a[k]);
                }
                --cnt[a[k]];
                if(cnt[a[k]]==0){
                    update(a[k]+1,-1);
                }
                if(v.size()==mex){
                    break;
                }
            }
            ans.push_back(mex);
            //compute new mex
            mex=0;
            int l=0,r=N+1;
            while(l<=r){
                int mid=(l+r)/2;
                int val=ask(mid);
                if(val>=mid){
                    mex=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            ++k;
        }
        printf("%d\n",(int)ans.size());
        for(int i:ans)printf("%d ",i);
        printf("\n");
    }
}