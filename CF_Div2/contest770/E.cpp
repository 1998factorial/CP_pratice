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
void answer(vector<vector<int>>ans){
    printf("YES\n");
    for(int i=0;i<ans.size();++i){
        for(int j:ans[i]){
            if(j)printf("L");
            else printf("R");
        }
        printf("\n");
    }
}
vector<int> undirected_eular_circuit(int n , int m , const vector<vector<pii>>& G){
    for(auto& E : G)if(E.size() & 1)return {}; // odd degree
    vector<vector<pii>::const_iterator> it(n);
    for(int i = 0; i < n; ++i)it[i] = G[i].begin();
    vector<int> ans;
    vector<bool> done(n) , vis(m + 1);
    function<void(int)> dfs = [&](int v){
        done[v] = true;
        for(auto& cur = it[v]; cur != G[v].end();){
            int nv = cur->x , eid = cur->y;
            if(!vis[abs(eid)]){
                vis[abs(eid)] = true;
                dfs(nv);
                ans.push_back(eid);
            }
            else cur = next(cur);
        }
    };
    for(int i = 0; i < n; ++i){
        if(!G[i].empty() && !done[i]){
            dfs(i);
        }
    }
    assert(ans.size() == m);
    reverse(ans.begin() , ans.end());
    return ans;
}
int main(){
    int M=read();
    vector<vector<int>>a,ans;
    map<int,int>freq;
    for(int i=1;i<=M;++i){
        int N=read();
        vector<int>tmp(N),val(N);
        for(int j=0;j<N;++j){
            tmp[j]=read();
            ++freq[tmp[j]];
        }
        a.push_back(tmp);
        ans.push_back(val);
    }
    int bad=0,tot=0;
    map<int,int>mp;
    for(auto&e:freq){
        if(e.y&1){
            bad=1;
        }
        mp[e.x]=++tot;
    }
    if(bad){
        printf("NO\n");
        return 0;
    }
    // build bipartite & connected graph.
    int num=0,nedges=0;
    map<pii,int>id;
    map<int,pii>rev;
    for(int i=0;i<M;++i){
        for(int j=0;j<a[i].size();++j){
            id[{i,j}]=++num;
            rev[num]={i,j};
        }
    }
    vector<vector<pii>>G(M+tot+10); // G[from]=<to,id(row,col)>
    for(int i=0;i<M;++i){
        for(int j=0;j<a[i].size();++j){
            int value=a[i][j],v=i,u=M-1+mp[value];
            G[v].push_back({u,id[{i,j}]});
            G[u].push_back({v,-id[{i,j}]});
            ++nedges;
        }
    }
    for(int i=0;i<M;++i){
        int v=i,u=M-1+tot+1;
        G[v].push_back({u,++num});
        G[u].push_back({v,-num});
        G[v].push_back({u,++num});
        G[u].push_back({v,-num});
        nedges+=2;
    }
    vector<int>ret=undirected_eular_circuit(M+tot+2,nedges,G);
    for(int i:ret){
        if(rev.count(abs(i))){
            auto t=rev[abs(i)];
            ans[t.x][t.y]=(i<0);
        }
    }
    answer(ans);
}