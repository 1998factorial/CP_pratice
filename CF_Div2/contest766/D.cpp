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
int read(){
	bool minus=false;
	int result=0;
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
int gcd(int x,int y){
    return x==0?y:gcd(y%x,x);
}
int main(){
    int N=read(),ans=0;
    vector<int>a(1000005);
    for(int i=1;i<=N;++i){
        int x=read();
        ++a[x];
    }
    for(int v=1;v<=1000000;++v){
        if(a[v])continue;
        int d=0;
        for(int u=v;u<=1000000;u+=v){
            if(a[u]){
                d=gcd(d,u);
            }
        }
        if(d==v){
            ++ans;
        }
    }
    printf("%d\n",ans);
}   