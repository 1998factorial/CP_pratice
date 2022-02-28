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
const int mod = 998244353;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int N,M,K,fa[300005],in[300005],out[300005];
vector<vector<int>>a;
ll dp[300005];
vector<int>comps[300005];
bool bad[300005];

ll add(ll x,ll y){
    return (x+y)%mod;
}
ll mul(ll x,ll y){
    return (x*y)%mod;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)fa[x]=fa[y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=1;i<=K;++i)fa[i]=i;
    set<pii>vis;
    for(int i=1;i<=N;++i){
        int sz;
        cin>>sz;
        vector<int>b(sz);
        for(int j=0;j<sz;++j)cin>>b[j];
        a.push_back(b);
        set<int>s(b.begin(),b.end());
        if(s.size()!=b.size()){
            for(int j:s){
                bad[j]=true;
            }   
            continue;
        }
        for(int j=0;j+1<sz;++j){
            merge(b[j],b[j+1]);
            if(vis.count({b[j],b[j+1]})==0){
                ++out[b[j]];
                ++in[b[j+1]];
            }
            vis.insert({b[j],b[j+1]});
        }
    }
    for(int i=1;i<=K;++i){
        comps[find(i)].push_back(i);
    }
    vector<int>sizes;
    for(int i=1;i<=K;++i){
        int ok=1,sz=0,in_zero=0,out_zero=0;
        for(int v:comps[i]){
            ++sz;
            if(in[v]>1||out[v]>1||bad[v])ok=0;
            if(in[v]==0)in_zero=1;
            if(out[v]==0)out_zero=1;
        }
        if(ok&&sz>0&&in_zero&&out_zero){
            sizes.push_back(sz);
        }
    }
    map<int,int>cnt;
    for(int i:sizes){
        ++cnt[i];
    }
    dp[0]=1;
    for(int i=1;i<=M;++i){
        for(auto&e:cnt){
            ll v=e.x,c=e.y;
            if(i-v>=0){
                dp[i]=add(dp[i],mul(dp[i-v],c));
            }
        }
    }
    cout<<dp[M]<<endl;
}