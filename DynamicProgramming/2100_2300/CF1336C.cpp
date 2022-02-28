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
char S[3005],T[3005],tmp[3005];
int N,M,dp[3005][3005],f[3005][26],b[3005][26];
int mul(int x,int y){
    return (ll)x*y%mod;
}
int add(int x,int y){   
    return ((ll)x+y)%mod;
}
int main(){
    scanf("%s",S+1);
    scanf("%s",T+1);
    int N=strlen(S+1);
    int M=strlen(T+1);
    for(int i=M+1;i<=N;++i){
        T[i]='*';
    }
    for(int i=1;i<=N;++i){
        if(T[i]==S[1]||T[i]=='*'){
            dp[i][i]=2;
        }
    }   
    for(int len=2;len<=N;++len){
        for(int i=1;i+len-1<=N;++i){
            int j=i+len-1;
            //put at front
            if(T[i]=='*'||S[len]==T[i]){
                dp[i][j]=add(dp[i][j],dp[i+1][j]);
            }
            //put at back
            if(T[j]=='*'||S[len]==T[j]){
                dp[i][j]=add(dp[i][j],dp[i][j-1]);
            }
        }
    }
    int ans=0;
    for(int i=M;i<=N;++i)ans=add(ans,dp[1][i]);
    printf("%d\n",ans);
}   