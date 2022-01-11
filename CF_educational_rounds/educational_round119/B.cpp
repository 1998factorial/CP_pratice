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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll W,H;
        cin>>W>>H;
        int sz;
        cin>>sz;
        vector<int>a(sz);
        for(int i=0;i<sz;++i)cin>>a[i];
        cin>>sz;
        vector<int>b(sz);
        for(int i=0;i<sz;++i)cin>>b[i];
        cin>>sz;
        vector<int>c(sz);
        for(int i=0;i<sz;++i)cin>>c[i];
        cin>>sz;
        vector<int>d(sz);
        for(int i=0;i<sz;++i)cin>>d[i];
        //ab or cd
        ll ans=0;
        ans=max(ans,H*(a.back()-a[0]));
        ans=max(ans,H*(b.back()-b[0]));
        ans=max(ans,W*(c.back()-c[0]));
        ans=max(ans,W*(d.back()-d[0]));
        cout<<ans<<endl;
    }
}   