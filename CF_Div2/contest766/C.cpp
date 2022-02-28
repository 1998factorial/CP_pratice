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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
vector<pii>g[100005];
void DFS(int v,int p,vector<int>&ans,int f){
    for(auto&e:g[v]){
        int nv=e.x,id=e.y;
        if(nv!=p){
            DFS(nv,v,ans,f^1);
            if(f)ans[id]=2;
            else ans[id]=3;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        for(int i=0;i<N-1;++i){
            int u,v;
            cin>>u>>v;
            g[u].push_back({v,i});
            g[v].push_back({u,i});
        }
        int ok=1;
        for(int i=1;i<=N;++i){
            if(g[i].size()>2)ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
        }
        else{
            vector<int>ans(N-1);
            int st=1;
            for(; st<=N;++st){
                if(g[st].size()==1)break;
            }
            DFS(st,st,ans,0);
            for(int i=0;i<N-1;++i){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        for(int i=1;i<=N;++i)g[i].clear();
    }
}   