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
        int N,m=0;
        cin>>N;
        vector<int>a(N);
        for(int i=0;i<N;++i)cin>>a[i],m=max(m,a[i]);
        int up=(m+2)/3+1,ans=up;
        for(int total=up-1;total<=up+1;++total){
            for(int two=0;two<=2;++two){
                for(int one=0;one<=2;++one){
                    int three=total-one-two;
                    if(three<0)continue;
                    int ok=1;
                    for(int i:a){
                        int ok2=0;
                        for(int u1=0;u1<=one;++u1){
                            for(int u2=0;u2<=two;++u2){
                                int v=u1*1+u2*2;
                                if(v%3!=i%3)continue;
                                int t=i-v;
                                if(t<0)continue;
                                if(three>=t/3){
                                    ok2=1;
                                }
                            }
                        }
                        if(ok2==0)ok=0;
                    }
                    if(ok){
                        ans=min(ans,total);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}   