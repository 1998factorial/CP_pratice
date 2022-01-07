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
const int mod = 1e9+7;
ll add(ll x, ll y){
    return (x+y)%mod;
}
ll mul(ll x,ll y){
    return x*y%mod;
}
ll sub(ll x,ll y){
    return ((x-y)%mod+mod)%mod;
}
ll qpow(ll x , ll n){
    ll ret=1ll;
    while(n){
        if(n % 2)ret=mul(ret,x);
        x=mul(x,x);
        n>>=1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N,M,rb,cb,rd,cd,p,pc;
        cin>>N>>M>>rb>>cb>>rd>>cd>>p;
        pc=100-p;
        p=mul(p,qpow(100ll,mod-2));
        pc=mul(pc,qpow(100ll,mod-2));
        int dr=1,dc=1,r=rb,c=cb,sr,sc;
        vector<array<int,3>> cycle;
        for(;;){
            if(r+dr>N||r+dr<1)dr*=-1;
            if(c+dc>M||c+dc<1)dc*=-1;
            if(cycle.empty())sr=dr,sc=dc;
            if(r==rb&&c==cb&&dr==sr&&dc==sc&&cycle.size()>0)break;
            cycle.push_back({r,c,(r==rd||c==cd)});
            r+=dr;
            c+=dc;
        }
        //E=u+v*E
        reverse(cycle.begin(),cycle.end());
        int u=1,v=1;
        for(auto&e:cycle){
            int coe=1;
            if(e[2]==1)coe=pc;
            u=mul(u,coe);
            v=mul(v,coe);
            u=add(u,1ll);
        }
        u=sub(u,1);
        int ans=mul(u,qpow(sub(1ll,v),mod-2));
        cout<<ans<<endl;
    }
}