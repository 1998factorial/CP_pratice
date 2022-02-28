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
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,l;
        cin>>n>>l;
        vector<int>x(n+1);
        for(int i=1;i<=n;++i)cin>>x[i];
        int ans=0;
        for(int i=0;i<l;++i){
            int b=(1<<i),cnt=0;
            for(int j=1;j<=n;++j){
                if(x[j]>>i&1)++cnt;
            }
            if(cnt*2>=n){
                ans|=b;
            }
        }
        cout<<ans<<endl;
    }
}  
