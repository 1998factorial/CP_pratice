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
int query(int i,int j,int k){
    printf("? %d %d %d\n",i,j,k);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}
void answer(int i,int j){
    printf("! %d %d\n",i,j);
    fflush(stdout);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N;
        scanf("%d",&N);
        //why
        vector<pii>vec;
        for(int i=3;i<=N;++i){
            int v=query(1,2,i);
            vec.push_back({v,i});
        }
        int min_id=-1,max_id=-1;
        sort(vec.begin(),vec.end());
        max_id=vec.back().y;
        min_id=vec[0].y;
        vector<pii>vec2;
        for(int i=1;i<=N;++i){
            if(i==min_id||i==max_id)continue;
            int v=query(min_id,max_id,i);
            vec2.push_back({v,i});
        }
        sort(vec2.begin(),vec2.end());
        if(vec[0].x==vec.back().x&&vec2[0].x==vec2.back().x){
            if(vec[0].x>vec2[0].x){
                answer(1,2);
                continue;
            }
        }
        if(vec2[0].x==vec2.back().x){
            answer(min_id,max_id);
        }
        else{
            int maxv2=-inf32,max_id2=-1;
            max_id2=vec2.back().y;
            answer(max_id,max_id2);
        }
    }
}