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
char a[55][55];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M,R,C;
        scanf("%d%d%d%d",&N,&M,&R,&C);
        for(int i=1;i<=N;++i){
            scanf("%s",(a[i]+1));
        }
        int ans=3;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                if(a[i][j]=='B'){
                    if(i==R&&j==C)ans=min(ans,0);
                    if(i==R||j==C)ans=min(ans,1);
                    if(i!=R&&j!=C)ans=min(ans,2);                    
                }
            }
        }
        printf("%d\n",(ans<3?ans:-1));
    }
}   