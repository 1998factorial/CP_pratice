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
int fa[maxn],v_root[maxn],root_v[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
}
const int M=10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q=50;
    cout<<q<<endl;
    while(q--){
        int c=gen()%2;
        if(c){
            cout<<1<<" "<<gen()%M+1<<endl;
        }
        else{
            cout<<2<<" "<<gen()%M+1<<" "<<gen()%M+1<<endl;
        }
    }
}