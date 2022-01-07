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
const int mod = 998244353;
int N,K,L[maxn],R[maxn],dep[maxn],ord[maxn],rord[maxn],tot=0;
bool candidate[maxn],duplicate[maxn];
char a[maxn],si[maxn];
void DFS(int v,int depth){
    dep[v]=depth;
    if(L[v]){
        DFS(L[v],depth+1);
    }
    si[++tot]=a[v];
    ord[v]=tot;
    rord[tot]=v;
    if(R[v]){
        DFS(R[v],depth+1);
    }
}
void DFS2(int v,int cost){
    if(v==0)return;
    if(cost>K)return;
    DFS2(L[v],cost+1);
    if(duplicate[L[v]]){
        duplicate[v]=true;
        debug printf("dup %d\n",v);
    }
    else if(candidate[v]){
        duplicate[v]=true;
        debug printf("dup %d\n",v);
        K-=cost;
    }
    if(duplicate[v]){
        DFS2(R[v],1);
    }
}
void build(int v){
    if(v==0)return;
    build(L[v]);
    cout<<a[v];
    if(duplicate[v])cout<<a[v];
    build(R[v]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;
    cin>>(a+1);
    for(int i=1;i<=N;++i){
        cin>>L[i]>>R[i];                
    }
    DFS(1,1);
    debug{
        for(int i=1;i<=N;++i)cout<<si[i];
        cout<<endl;
    }
    char lastc=si[N];
    for(int i=N-1;i>=1;--i){
        if(si[i]!=si[i+1]){
            lastc=si[i+1];
        }
        if(lastc>si[i]){
            candidate[rord[i]]=true; // worth to duplicate
        }
    }
    debug{
        for(int i=1;i<=N;++i){
            if(candidate[i])cout<<i<<" ";
        }
        cout<<endl;
    }
    DFS2(1,1);
    build(1);
    cout<<endl;
}