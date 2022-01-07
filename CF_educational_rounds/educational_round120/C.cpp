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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        ll K;
        cin>>N>>K;
        vector<ll>a(N+1),s(N+1);
        for(int i=1;i<=N;++i)cin>>a[i];
        sort(a.begin()+1,a.end());
        for(int i=1;i<=N;++i)s[i]+=s[i-1],s[i]+=a[i];
        ll ans=inf64;
        ll l=0,r=(ll)inf32*10,sum=s[N];
        while(l<=r){
            ll mid=(l+r)/2;
            int ok=0,i=2;
            for(ll num=N-1;num>=0;--num,++i){
                if(mid<num)continue;
                ll x=a[1]-(mid-num);
                ll v=sum-a[1]+x;
                v-=(s[N]-s[i-1]);
                v+=num*x;
                if(v<=K)ok=1;
            }
            if(ok){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<endl;
    }
}