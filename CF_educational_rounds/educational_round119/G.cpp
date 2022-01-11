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
int N,cnt[25][26],val[(1<<23)+10][26];
string s[25];
ll dp[(1<<23)+10];
ll mul(ll x,ll y){
    return x*y%mod;
}
ll add(ll x,ll y){
    return ((x+y)%mod+mod)%mod;
}
ll F(int i){
    ll ans=1;
    for(int j=0;j<26;++j){
        ans=mul(ans,add(val[i][j],1));
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>s[i];
        for(int j=0;j<s[i].size();++j){
            ++cnt[i][s[i][j]-'a'];
        }
        for(int j=0;j<26;++j){
            val[1<<i][j]=cnt[i][j];
        }
    }
    for(int mask=1;mask<1<<N;++mask){
        if(__builtin_popcount(mask)<2)continue;
        int i=0;
        for(;i<N;++i)if(mask>>i&1)break;
        for(int j=0;j<26;++j){
            val[mask][j]=min(val[mask^(1<<i)][j],val[1<<i][j]);
        }
    }
    for(int mask=1;mask<1<<N;++mask){
        dp[mask]=F(mask);
        ll sign=(__builtin_popcount(mask)&1)?1:-1;
        dp[mask]=mul(dp[mask],sign);
    }
    for(int i=0;i<N;++i){
        for(int mask=0;mask<1<<N;++mask){
            if(mask>>i&1){
                dp[mask]=add(dp[mask],dp[mask^(1<<i)]);
            }
        }
    }
    /*for(int mask=1;mask<1<<N;++mask){
        for(int submask=mask;submask;submask=(submask-1)&mask){
            dp[mask]=add(dp[mask],f[submask]);
        }
    }*/
    ll ans=0;
    for(int mask=1;mask<1<<N;++mask){
        ll sz=__builtin_popcount(mask),sm=0;
        for(int i=0;i<N;++i)if(mask>>i&1)sm=add(sm,i+1);
        sz*=sm;
        sz*=dp[mask];
        //printf("dp[%d]=%lld\n",mask,dp[mask]);
        ans^=sz;
    }
    cout<<ans<<endl;
}