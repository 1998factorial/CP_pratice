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
vector<int>g[200005];
int color[200005];
bool vis[200005];
void DFS(int v,int c){
    vis[v]=true;
    color[v]=c;
    for(int nv:g[v]){
        if(vis[nv]==false){
            DFS(nv,c^1);
        }
    }
}
int main(){
    int M=read(),tot=0;
    map<pii,int>id;
    map<int,pii>rev;
    vector<vector<int>>a,ans;    
    map<int,vector<int>>pos;
    for(int i=0;i<M;++i){
        int sz=read();
        vector<int>tmp(sz),val(sz);
        for(int j=0;j<sz;++j){
            tmp[j]=read();
            id[{i,j}]=++tot;
            rev[tot]={i,j};
            pos[tmp[j]].push_back(id[{i,j}]);
        }
        a.push_back(tmp);
        ans.push_back(val);
    }
    int bad=0;
    for(const auto&e:pos){
        if(e.y.size()&1){
            bad=1;
        }
    }
    if(bad){
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<M;++i){
        for(int j=0;j<a[i].size();j+=2){
            g[id[{i,j}]].push_back(id[{i,j+1}]);
            g[id[{i,j+1}]].push_back(id[{i,j}]);
        }
    }
    for(const auto&e:pos){
        const auto vec=e.y;
        for(int j=0;j<vec.size();j+=2){
            g[vec[j]].push_back(vec[j+1]);
            g[vec[j+1]].push_back(vec[j]);
        }
    }
    for(int i=1;i<=tot;++i){
        if(vis[i]==false){
            DFS(i,0);
        }
    }
    printf("YES\n");
    for(int i=1;i<=tot;++i){
        ans[rev[i].x][rev[i].y]=color[i];
    }
    for(int i=0;i<M;++i){
        for(int j=0;j<ans[i].size();++j){
            if(ans[i][j])printf("L");
            else printf("R");
        }
        printf("\n");
    }
}   