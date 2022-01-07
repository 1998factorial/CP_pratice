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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<array<ll,3>> vec(N);
        for(int i=0;i<N;++i){
            cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
        }
        ll ans=inf64;
        ll l=inf32,r=-inf32;
        map<ll,ll>lc,rc;
        for(int i=0;i<N;++i){
            if(l>vec[i][0]&&r<vec[i][1]){
                ans=vec[i][2];
            }
            if(l<=vec[i][0]&&r>=vec[i][1]){
                if(l==vec[i][0]&&r==vec[i][1]){
                    ans=min(ans,vec[i][2]);
                }
            }
            if(l>vec[i][0]&&r>=vec[i][1]){
                ll cost=vec[i][2]+rc[r];
                if(r==vec[i][1])cost=vec[i][2];
                ans=min(ans,cost);
            }
            if(l<=vec[i][0]&&r<vec[i][1]){
                ll cost=vec[i][2]+lc[l];
                if(l==vec[i][0])cost=vec[i][2];
                ans=min(ans,cost);
            }
            if(lc.count(vec[i][0])==0)lc[vec[i][0]]=vec[i][2];
            else lc[vec[i][0]]=min(lc[vec[i][0]],vec[i][2]);
            if(rc.count(vec[i][1])==0)rc[vec[i][1]]=vec[i][2];
            else rc[vec[i][1]]=min(rc[vec[i][1]],vec[i][2]);
            l=min(l,vec[i][0]);
            r=max(r,vec[i][1]);
            cout<<ans<<endl;
        }
    }
}