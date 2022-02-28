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
ll cal(ll x,ll y){
    return (x+y)*(y-x+1)/2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<ll>K(N+1),H(N+1);  //(k,h)
        for(int i=1;i<=N;++i)cin>>K[i];
        for(int i=1;i<=N;++i)cin>>H[i];
        ll mana=0,power=0;
        for(int i=1;i<=N;++i){
            ll v=K[i]-H[i]+1;
            for(int j=i+1;j<=N;++j){
                v=min(v,K[j]-H[j]+1);
            }
            ll time=K[i]-K[i-1];
            if(v<=K[i-1]){
                mana+=cal(power+1,power+time);
                power+=time;
            }
            else{
                power=0;
                time=K[i]-v+1;
                mana+=cal(power+1,power+time);
                power+=time;
            }
        }
        cout<<mana<<endl;
    }
}   