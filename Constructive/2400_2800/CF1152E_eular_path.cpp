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
struct Indexer{
    unordered_map<int,int>mp;
    vector<int>num;
    int add(int x){
        if(!mp.count(x)){
            mp[x]=num.size();
            num.push_back(x);
        }
        return mp[x];
    }
    int getNum(int x){
        return num[x];
    }
    int size(){
        return mp.size();
    }
};
struct Edge{
    int x,y;
    bool f;
    Edge(){}
    Edge(int x_,int y_,bool f_):x(x_),y(y_),f(f_){}
};
struct Graph{
    // index start with 0
    int n;
    vector<Edge>edges;
    vector<vector<int>>g;
    vector<int>pos;
    list<int>path;
    void DFS(list<int>::iterator it,int u){ // DFS (with euler path finding purpose)
        for(;pos[u]<g[u].size();++pos[u]){
            int id=g[u][pos[u]];
            if(edges[id].f){
                edges[id].f=0;
                int v=edges[id].x+edges[id].y-u;
                DFS(path.insert(it,u),v);
            }
        }
    }
    Graph(int n_):n(n_){
        g.assign(n,vector<int>());
    }
    void addEdge(int v,int u){ // add undirected edge
        g[v].push_back(edges.size());
        g[u].push_back(edges.size());
        edges.emplace_back(v,u,0);
    }
    vector<int> eulerPath(){ // find euler path, in vertices form
        for(auto& e:edges)e.f=1;
        path.clear();
        pos.assign(n,0);
        vector<int>odd;
        for(int u=0;u<n;++u){
            if(g[u].size()%2==1)odd.push_back(u);
        }
        if(odd.empty()){
            odd.push_back(0);
            odd.push_back(0);
        }
        if(odd.size()>2){
            return {};
        }
        DFS(path.begin(),odd[0]);
        path.insert(path.begin(),odd[1]);
        return vector<int>(path.begin(),path.end());
    }
};
int main(){
    int N=read();
    vector<int>b(N),c(N);
    for(int i=1;i<=N-1;++i){
        b[i]=read();
    }
    for(int i=1;i<=N-1;++i){
        c[i]=read();
    }
    int invalid=0;
    for(int i=1;i<=N-1;++i){
        if(c[i]<b[i]){
            invalid=1;
        }
    }
    if(invalid){
        printf("-1\n");
        return 0;
    }
    Indexer I;
    for(int i=1;i<=N-1;++i){
        b[i]=I.add(b[i]);
        c[i]=I.add(c[i]);
    }
    Graph G=Graph(I.size());
    for(int i=1;i<=N-1;++i){
        G.addEdge(b[i],c[i]);
    }
    vector<int>ans=G.eulerPath();
    if(ans.size()<N){
        printf("-1");
    }
    else{
        for(int i:ans)printf("%d ",I.getNum(i));
        printf("\n");
    }
}   