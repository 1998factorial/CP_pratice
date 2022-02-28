#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(0)
#define DEBUG(x) std::cout << #x << '=' << x << std::endl
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int N,colour[maxn],ans[maxn],B[maxn],next_B[maxn];
vector<int>g[maxn];
int bb=0,cc=0;
bool is_bb(int v){
    return colour[v]&&B[v]>=2;
}
bool is_cc(int v){
    if(B[v]>=2){
        return next_B[v];
    }
    return false;
}
void DFS(int v,int p){
    B[v]+=colour[v];
    for(int nv:g[v]){
        if(nv!=p){
            DFS(nv,v);
            B[v]+=B[nv];
        }
    }
    bb+=is_bb(v);
    cc+=is_cc(v);
}
void reroot(int from,int to){
    bb-=is_bb(from);
    bb-=is_bb(to);
    cc-=is_cc(from);
    cc-=is_cc(to);
    int x=B[from],y=B[to];
    B[to]=x;
    B[from]=x-y;
    bb+=is_bb(from);
    bb+=is_bb(to);
    cc+=is_cc(from);
    cc+=is_cc(to);
}
void DFS2(int v,int p){
    if(colour[v]||next_B[v]||bb||cc)ans[v]=1;
    for(int nv:g[v]){
        if(nv!=p){
            reroot(v,nv);
            DFS2(nv,v);
            reroot(nv,v);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;++i)cin>>colour[i];
    for(int i=1;i<N;++i){
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i=1;i<=N;++i){
        for(int j:g[i]){
            if(colour[j]){
                next_B[i]=1;
                break;
            }
        }
    }
    DFS(1,1);
    DFS2(1,1);
    for(int i=1;i<=N;++i)cout<<ans[i]<<" ";
    cout<<endl;
}   