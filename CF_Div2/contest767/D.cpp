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
const ll mod=998244353;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
ll read(){
	bool minus=false;
	ll result=0;
	char ch;
	ch=getchar();
	while(true){
		if(ch=='-')break;
		if(ch>='0'&&ch<='9')break;
		ch=getchar();
	}
	if(ch == '-')minus=true;
    else result=ch-'0';
	while(true){
		ch=getchar();
		if(ch<'0'||ch>'9')break;
		result=result*10+(ch-'0');
	}
	if(minus)
		return -result;
	else
		return result;
}
inline ll add(ll x,ll y){
    return ((x+y)%mod+mod)%mod;
}
inline ll mul(ll x,ll y){
    return x*y%mod;
}
inline ll qpow(ll x,ll n){
    ll ret=1ll;
    while(n){
        if(n&1)ret=mul(ret,x);
        x=mul(x,x);
        n>>=1;
    }
    return ret;
}
ll gcd(ll n,ll m){
    return n==0?m:gcd(m%n,n);
}
ll lcm(ll n,ll m){
    return n*m/gcd(n,m);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N,ok=0;
        cin>>N;
        vector<string>s(N);
        for(int i=0;i<N;++i){
            cin>>s[i];
            if(s[i].size()==1){
                ok=1;
            }
            if(s[i].size()==2&&s[i][0]==s[i][1]){
                ok=1;
            }
            if(s[i].size()==3&&s[i][0]==s[i][2]){
                ok=1;
            }
        }
        if(ok){
            cout<<"YES"<<endl;
            continue;
        }
        map<string,int>vis2,vis3;
        for(string ss:s){
            if(ss.size()==2){
                string prefix="aa";
                prefix[0]=ss[1],prefix[1]=ss[0];
                //2+2 or 3+2
                if(vis2[prefix]>0){
                    ok=1;
                }
                for(char x='a';x<='z';++x){
                    string t=prefix;
                    t+=x;
                    if(vis3[t]>0){
                        ok=1;
                    }
                }
                ++vis2[ss];
            }
            if(ss.size()==3){
                string prefix2="aa",prefix3="aaa";
                prefix2[0]=ss[2],prefix2[1]=ss[1];
                prefix3[0]=ss[2],prefix3[1]=ss[1],prefix3[2]=ss[0];
                //2+3 or 3+3
                if(vis2[prefix2]>0||vis3[prefix3]>0){
                    ok=1;
                }
                ++vis3[ss];
            }
        }
        if(ok){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}