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
const int maxn = 1e6 + 10;
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
int a[505][505],N,M,b[505][505];
int gcd(int x,int y){
    return x==0?y:gcd(y%x,x);
}
int main(){
    N=read();
    M=read();
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            a[i][j]=read();
        }
    }
    int lcm=1;
    for(int i=1;i<=16;++i){
        lcm=lcm*i/(gcd(lcm,i));
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if((i+j)&1){
                b[i][j]=lcm;
            }
            else{
                b[i][j]=lcm+a[i][j]*a[i][j]*a[i][j]*a[i][j];
            }
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}   