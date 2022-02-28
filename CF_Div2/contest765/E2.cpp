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
int N,Q,p[300005],fa[300005],nson[300005],idx[300005];
char a[300005];
vector<ll> trees[300005];
ll tree[300005*4];
void upd(int pos,ll val){
    while(pos<=N){
        tree[pos]+=val;
        pos+=pos&(-pos);
    }
}
ll query(int pos){
    ll ret=0;
    while(pos>0){
        ret+=tree[pos];
        pos-=pos&(-pos);
    }
    return ret;
}
void upd(int at,int pos,ll val){
    while(pos<=nson[at]){
        trees[at][pos]+=val;
        pos+=pos&(-pos);
    }
}
ll query(int at,int pos){
    ll ret=0;
    while(pos>0){
        ret+=trees[at][pos];
        pos-=pos&(-pos);
    }
    return ret;
}
int main(){
    scanf("%d%d",&N,&Q);
    scanf("%s",a+1);
    vector<int>st;
    st.push_back(0);
    for(int i=1;i<=N;++i){
        if(a[i]=='('){
            if(!st.empty()){
                int v=st.back();
                ++nson[v];
                idx[i]=nson[v]; // i is v's nson[v]-th child
                fa[i]=v; // i's father is v
            }
            st.push_back(i);
        }
        else if(a[i]==')'){
            if(st.size()>1){
                idx[i]=idx[st.back()]; // we find a (RBS)
                fa[i]=fa[st.back()];
                st.pop_back();
            }
        }
    }
    for(int i=0;i<=N;++i){
        trees[i]=vector<ll>(nson[i]*4,0);
        for(int j=1;j<=nson[i];++j){
            upd(i,j,1);
        }
    }
    for(int i=0;i<=N;++i){
        if(a[i]=='('){
            upd(i,(ll)nson[i]*(nson[i]+1)/2);
        }
    }
    while(Q--){
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1){
            // erase a[l] and a[r]
            int v=fa[l];
            ll val=query(v,nson[v]);
            if(v>0)upd(v,-val);
            upd(v,idx[l],-1);
        }
        else{
            // a[l]='('
            ll ans=0;
            ans+=query(r)-query(l-1);
            int v=fa[l];
            ll val=query(v,idx[r])-query(v,idx[l]-1);
            ans+=(val)*(val+1)/2;
            printf("%lld\n",ans);
        }
    }
}