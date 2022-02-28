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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int cal(int x){
    if(__builtin_popcount(x)==1){
        return 0;
    }
    if(__builtin_popcount(x)==0){
        return 1;
    }
    int h=0;
    for(int i=0;i<=18;++i)if(x>>i&1)h=i;
    ++h;
    return (1<<h)-x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,N;
    cin>>t;
    while(t--){
        cin>>N;
        vector<ll>s(N+1);
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            ++s[x];
        }
        for(int i=1;i<=N;++i){
            s[i]+=s[i-1];
        }
        int ans=inf32;
        for(int x=1;x<=N;++x){
            for(int y=x+1;y<=N;++y){
                ll a=s[x],b=s[y]-s[x],c=s[N]-s[y];
                ans=min(ans,cal(a)+cal(b)+cal(c));
            }
        }
        cout<<ans<<endl;
    }
}   