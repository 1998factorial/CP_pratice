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
int fa[55];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);y=find(y);fa[x]=y;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        int N=a.size(),ok=1;
        for(int i=0;i<N;++i)fa[i]=i;
        for(int i=0;i<N;++i){
            if(a[i]=='E'){
                merge(i,(i+1)%N);
            }
        }
        for(int i=0;i<N;++i){
            if(a[i]=='N'){
                int ni=(i+1)%N;
                if(find(i)==find(ni))ok=0;
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}   