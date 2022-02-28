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
const ll mod=1e9+7;
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
int num=0,in_deg[80*80],out_deg[80*80];
map<string,int>mp;
map<int,string>rev;
vector<int>g[80*80];
string ans="";
void DFS(int v){
    for(;!g[v].empty();){
        int nv=g[v].back();
        g[v].pop_back();
        DFS(nv);
    }
    ans+=rev[v][1];
}
int main(){
    int N=read();
    vector<char>a;
    for(char i='a';i<='z';++i){
        a.push_back(i);
    }
    for(char i='A';i<='Z';++i){
        a.push_back(i);
    }
    for(char i='0';i<='9';++i){
        a.push_back(i);
    }
    for(char x:a){
        for(char y:a){
            string t="";
            t+=x,t+=y;
            mp[t]=num;
            rev[num]=t;
            ++num;
        }
    }
    for(int i=1;i<=N;++i){
        char a[5];
        scanf("%s",a);
        string u="",v="";
        u+=a[0],u+=a[1];
        v+=a[1],v+=a[2];
        int from=mp[u],to=mp[v];
        ++out_deg[from];
        ++in_deg[to];
        g[from].push_back(to);
    }
    // in directed graph, eular path exists iff at most one in(v)-out(v)=1 and in(u)-out(u)=-1
    int n_in=0,n_out=0,invalid=0;
    for(int i=0;i<num;++i){
        if(in_deg[i]-out_deg[i]==1){
            ++n_in;
        }
        if(in_deg[i]-out_deg[i]==1){
            ++n_out;
        }
        if(abs(in_deg[i]-out_deg[i])>1){
            invalid=1;
        }
    }
    //DEBUG(n_in);
    //DEBUG(n_out);
    //DEBUG(invalid);
    if(invalid||n_in!=n_out||n_in>1){
        printf("NO\n");
        return 0;
    }
    int start=0;
    for(;start<num;++start){
        if(n_in&&out_deg[start]-in_deg[start]==1){
            break;
        }
        if(!n_in&&out_deg[start]>0){
            break;
        }
    }
    DFS(start);
    ans+=rev[start][0];
    reverse(ans.begin(),ans.end());
    if(ans.size()>=N+2){
        printf("YES\n%s\n",ans.c_str());
    }
    else{
        printf("NO\n");
    }
}   