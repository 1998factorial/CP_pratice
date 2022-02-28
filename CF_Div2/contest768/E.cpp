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
const int maxn = 2e5 + 10;
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
int a[200005];
int dp[200005];
int occ[200005];
vector<int>pos[200005];

struct max_lazy_tree{

    struct node{
        ll val , lazy;
        node(){}
        node(ll v , ll z) : val(v) , lazy(z) {}
    };

    node tree[maxn * 4 + 100];

    void push_down(int l , int r , int id){
        if(l > r)return;
        if(tree[id].lazy != 0 && l < r){
            tree[id << 1].lazy += tree[id].lazy;
			tree[id << 1 | 1].lazy += tree[id].lazy;
			tree[id << 1].val += tree[id].lazy;
			tree[id << 1 | 1].val += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }

    node merge(node l , node r){
        node ret(0 , 0);
        if(l.val > r.val){
            ret.val = l.val;
        }
        else{
            ret.val = r.val;
        }
        return ret;
    }

    void build(int l , int r , int id){
        if(l > r)return;
        if(l == r){
            tree[id].val = 0;
            tree[id].lazy = 0;
        }
        else{
            int mid = (l + r) >> 1;
            build(l , mid , id << 1);
            build(mid + 1 , r , id << 1 | 1);
            tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
        }
    }

    void range_update(int l , int r , int x , int y , int id , ll v){ // support range update
        if(l > r || x > y || r < x || l > y)return;
        push_down(x , y , id);
        if(l <= x && y <= r){
            tree[id].val += v;
            tree[id].lazy += v;
            return;
        }
        int mid = (x + y) >> 1;
        if(r <= mid){
            range_update(l , r , x , mid , id << 1 , v);
        }
        else if(l > mid){
            range_update(l , r , mid + 1 , y , id << 1 | 1 , v);
        }
        else{
            range_update(l , r , x , mid , id << 1 , v);
            range_update(l , r , mid + 1 , y , id << 1 | 1 , v);
        }
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }

    void point_update(int pos , int l , int r , int id , ll v){
        if(pos < l || pos > r || l > r)return;
        push_down(l , r , id);
        if(pos == l && pos == r){
            tree[id].val += v;
            return ;
        }
        int mid = (l + r) >> 1;
        if(pos <= mid){
            point_update(pos , l , mid , id << 1 , v);
        }
        else{
            point_update(pos , mid + 1 , r , id << 1 | 1 , v);
        }
        tree[id] = merge(tree[id << 1] , tree[id << 1 | 1]);
    }

    /*int query(int l , int r , int id){
        if(tree[id].val <= 0)return -1;
        if(l == r)return l;
        push_down(l , r , id);
        int mid = (l + r) >> 1;
        if(tree[id << 1 | 1].val > 0)return query(mid + 1 , r , id << 1 | 1);
        return query(l , mid , id << 1);
    }*/

    ll query(int l , int r , int x , int y , int id){
        if(l > r || x > y || y < l || x > r)return -inf64;
        push_down(x , y , id);
        if(l <= x && y <= r){
            return tree[id].val;
        }
        int mid = (x + y) >> 1;
        if(r <= mid){
            return query(l , r , x , mid , id << 1);
        }
        if(l > mid){
            return query(l , r , mid + 1 , y , id << 1 | 1);
        }
        return max(
            query(l , r , x , mid , id << 1) ,
            query(l , r , mid + 1 , y , id << 1 | 1)
        );
    }

} T;

int main(){
    int N=read();
    for(int i=1;i<=N;++i)occ[i]=inf32;
    for(int i=1;i<=N;++i){
        a[i]=read();
        occ[a[i]]=min(i,occ[a[i]]);
    }
    T.build(1,N,1);
    for(int i=1;i<=N;++i){
        dp[i]=max(dp[i],dp[i-1]);
        int v=-inf32,l=occ[a[i]],r=i-1;
        if(l<=r){
            v=max(v,(int)T.query(l,r,1,N,1));
        }
        dp[i]=max(dp[i],v+i);
        T.point_update(i,1,N,1,dp[i]-i-1);
    }
    printf("%d\n",dp[N]);
}