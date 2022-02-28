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
void answer(vector<vector<int>>ans){
    printf("YES\n");
    for(int i=0;i<ans.size();++i){
        for(int j:ans[i]){
            if(j)printf("L");
            else printf("R");
        }
        printf("\n");
    }
}
int main(){
    int M=read();
    vector<vector<int>>a;
    map<int,int>freq;
    for(int i=1;i<=M;++i){
        int N=read();
        vector<int>tmp(N);
        for(int j=0;j<N;++j){
            tmp[j]=read();
            ++freq[tmp[j]];
        }
        a.push_back(tmp);
    }
    int bad=0;
    for(auto&e:freq){
        if(e.y&1){
            bad=1;
        }
    }
    if(bad){
        printf("NO\n");
        return 0;
    }
    vector<vector<int>>ans;
    vector<vector<pii>>vec;
    vector<vector<bool>>vis;
    for(int i=0;i<M;++i){
        map<int,int>cnt,occ,parity;
        int sz=a[i].size();
        for(int j=0;j<sz;++j){
            ++cnt[a[i][j]];
        }
        vector<pii>tmp;
        vector<bool>tvis(sz);
        vector<int>val(sz);
        for(int j=sz-1;j>=0;--j){
            if(cnt[a[i][j]]&1&&occ.count(a[i][j])==0){
                occ[a[i][j]]=j;
                tmp.push_back({j,a[i][j]});
                tvis[j]=true;
            }
        }
        for(int j=0;j<sz;++j){
            if(tvis[j])continue;
            val[j]=parity[a[i][j]];
            parity[a[i][j]]^=1;
        }
        vec.push_back(tmp);
        vis.push_back(tvis);
        ans.push_back(val);
    }
    map<int,int>p;
    /*for(int i=0;i<M;++i){
        printf("show row %d\n",i);
        for(int j=0;j<vec[i].size();++j){
            printf("(%d %d) ",vec[i][j].x,vec[i][j].y);
        }
        printf("\n");
    }*/
    int start=0;
    while(start<M&&vec[start].empty())++start;
    if(start<M){
        for(int i=0;i<vec[start].size()/2;++i){
            int col=vec[start][i].x,value=vec[start][i].y;
            ans[start][col]=p[value];
            p[value]^=1;
        }
        for(int i=vec[start].size()/2;i<vec[start].size();++i){
            int col=vec[start][i].x,value=vec[start][i].y;
            p[value]^=1;
            ans[start][col]=p[value];
            p[value]^=1;
        }
    }
    for(int i=start+1;i<M;++i){
        int sz=vec[i].size();
        for(int j=0;j<sz;++j){
            int col=vec[i][j].x,value=vec[i][j].y;
            ans[i][col]=p[value];
            p[value]^=1;
        }
    }
    answer(ans);
}