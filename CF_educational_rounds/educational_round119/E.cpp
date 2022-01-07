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
int fa[maxn],v_root[maxn],root_v[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int q,cnt=0;
    scanf("%d",&q);
    while(q--){
        int tp;
        scanf("%d",&tp);
        if(tp==1){
            int x;
            scanf("%d",&x);
            ++cnt;
            fa[cnt]=cnt;
            if(v_root[x]==0){
                v_root[x]=cnt;
                root_v[cnt]=x;
            }
            else{
                merge(v_root[x],cnt);
            }
        }
        else{
            int x,y;
            scanf("%d %d",&x,&y);
            if(v_root[x]==0){
                continue;
            }
            if(v_root[y]==0){
                v_root[y]=v_root[x];
                root_v[v_root[y]]=y;
            }
            else{
                root_v[v_root[x]]=y;
                merge(v_root[y],v_root[x]);
            }
            if(x!=y)v_root[x]=0;
        }
    }
    for(int i=1;i<=cnt;++i){
        printf("%d ",root_v[find(i)]);
    }
    printf("\n");
}