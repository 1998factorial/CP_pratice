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
int dis(int i,int j,int x,int y){
    return abs(i-x)+abs(j-y);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N,M;
        scanf("%d%d",&N,&M);
        vector<int>vec;
        vector<pii>pt={{1,1},{1,M},{N,1},{N,M}};
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                int val=0;
                for(auto e:pt){
                    val=max(val,dis(i,j,e.x,e.y));
                }
                vec.push_back(val);
            }   
        }
        sort(vec.begin(),vec.end());
        for(int i:vec){
            printf("%d ",i);
        }
        printf("\n");
    }
}   