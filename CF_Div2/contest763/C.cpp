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
const int maxn = 3e5 + 10;
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
        int N;
        cin>>N;
        vector<ll>h(N+1);
        ll l=1e9,r=1e9,ans=0;
        for(int i=1;i<=N;++i)cin>>h[i],l=min(l,h[i]);
        while(l<=r){
            ll mid=(l+r)/2;
            vector<ll>inc(N+1);
            bool ok=true;
            for(int i=N;i>=1;--i){
                if(inc[i]+h[i]<mid){
                    ok=false;
                    break;
                }
                ll v=inc[i]+h[i]-mid;
                v=min(v,h[i])/3;
                if(i>=3){
                    inc[i-1]+=v;
                    inc[i-2]+=v*2;
                }
            }
            if(ok){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans<<endl;
    }   
}