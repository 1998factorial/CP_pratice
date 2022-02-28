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
void dfs(int v,vector<vector<pii>::const_iterator>& it, const vector<vector<pii>>& G, vector<bool>& done, vector<bool>& vis, vector<int>& ans){
    done[v] = true;
    for(auto& cur = it[v]; cur != G[v].end();){
        int nv = cur->x , eid = cur->y;
        if(!vis[abs(eid)]){
            vis[abs(eid)] = true;
            dfs(nv,it,G,done,vis,ans);
            ans.push_back(eid);
        }
        else cur = next(cur);
    }
}
vector<int> undirected_eular_circuit(int n , int m , const vector<vector<pii>>& G){
    for(auto& E : G)if(E.size() & 1)return {}; // odd degree
    vector<vector<pii>::const_iterator> it(n);
    for(int i = 0; i < n; ++i)it[i] = G[i].begin();
    vector<int> ans;
    vector<bool> done(n) , vis(m + 1);
    /*function<void(int)> dfs = [&](int v){
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
    };*/
    for(int i = 0; i < n; ++i){
        if(!G[i].empty() && !done[i]){
            dfs(i,it,G,done,vis,ans);
        }
    }
    assert(ans.size() == m);
    reverse(ans.begin() , ans.end());
    return ans;
}
int N,M;
int main(){
    N=read();
    M=read();
    vector<pii>edges;
    vector<vector<pii>>G(N+5);
    vector<int>col(M+5,-1);
    for(int i=0;i<M;++i){
        int u=read(),v=read();
        --u,--v;
        edges.push_back({u,v});
        G[u].push_back({v,i});
        G[v].push_back({u,-i});
    }
    if(M<=(N+M+1)/2){
        printf("%d\n",M);
        for(const auto&e:edges){
            printf("%d %d\n",e.x+1,e.y+1);
        }
        return 0;
    }
    //for(int i=0;i<N;++i){
    //    printf("deg[%d]=%d\n",i,(int)G[i].size());
    //}
    //printf("max keep = %d\n",(N+M+1)/2);
    int sink=N;
    int extra=0;
    for(int i=0;i<N;++i){
        if(G[i].size()&1){
            ++extra;
            G[i].push_back({sink,M-1+extra});
            G[sink].push_back({i,-(M-1+extra)});
            edges.push_back({i,sink});
        }
    }
    vector<int>ans=undirected_eular_circuit(N+1,(int)edges.size(),G);
    int c=0;
    for(const int&i:ans){
        if(abs(i)<M)col[abs(i)]=c;
        c^=1;
    }
    vector<int>deg(N);
    for(int i=0;i<M;++i){
        int u=edges[i].x,v=edges[i].y;
        if(col[i]){
            ++deg[u],++deg[v];
        }
        else{
            --deg[u],--deg[v];
        }
    }
    for(int i=0;i<M;++i){
        int u=edges[i].x,v=edges[i].y;
        if(col[i])continue;
        if(deg[u]<0||deg[v]<0){
            ++deg[u];
            ++deg[v];
            col[i]^=1;
        }
    }
    int cnt=0;
    for(int i=0;i<M;++i){
        if(col[i]){
            ++cnt;
        }
    }
    //assert((int)keep.size()<=(N+M+1)/2);
    //for(int i=0;i<N;++i){
    //    assert(deg[i]>=0);
    //}
    printf("%d\n",cnt);
    for(int i=0;i<M;++i){
        if(col[i]){
            printf("%d %d\n",edges[i].x+1,edges[i].y+1);
        }
    }
}   

    /*
    for(int m=1;m<=7500;++m){
        for(int n=1;n<=7500;++n){
            if(m>(n+m+1)/2){
                assert(
                    (m+1)/2-(n+1)/2>=m-(n+m+1)/2
                );
            }
        }
    }
    */