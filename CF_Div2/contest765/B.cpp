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
int t,n,a[150010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    map<int,int>p;
    for(int i=1;i<=n;++i){
        if(p.count(a[i])){
            int v=p[a[i]];
            ans=max(ans,v+(n-i));
        }
        p[a[i]]=i;
    }
    if(ans==0)--ans;
    cout<<ans<<endl;
  }
}