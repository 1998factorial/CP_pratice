#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define debug if(1)
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
int main(){
    int t;
    t=read();
    while(t--){
        int N,K;
        N=read();
        K=read();
        vector<vector<int>>vertical(K+10,vector<int>(K+10));
        vector<vector<int>>horizontal(K+10,vector<int>(K+10));
        for(int i=1;i<=N;++i){
            int r1,c1,r2,c2;
            r1=read();
            c1=read();
            r2=read();
            c2=read();
            if(r1==r2){
                int r=r1,c=max(c1,c2);
                ++vertical[r][c];
                ++vertical[K-r+1][K-c+2];
            }
            else{
                int r=min(r1,r2),c=c1;
                ++horizontal[r][c];
                ++horizontal[K-r][K-c+1];
            }
        }
        // run dijstra
        vector<vector<int>> dis(K+10,vector<int>(K+10,inf32));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
        q.push({0,K/2,K/2+1});//(d,r,c)
        dis[K/2][K/2+1]=0;
        while(!q.empty()){
            auto vec=q.top();
            q.pop();
            int d=vec[0],r=vec[1],c=vec[2];
            if(d>dis[r][c])continue;
            //up
            if(r-1>=0&&dis[r-1][c]>d+vertical[r][c]){
                dis[r-1][c]=d+vertical[r][c];
                q.push({dis[r-1][c],r-1,c});
            }
            //down
            if(r+1<=K&&dis[r+1][c]>d+vertical[r+1][c]){
                dis[r+1][c]=d+vertical[r+1][c];
                q.push({dis[r+1][c],r+1,c});
            }
            //right
            if(c+1<=K+1&&dis[r][c+1]>d+horizontal[r][c]){
                dis[r][c+1]=d+horizontal[r][c];
                q.push({dis[r][c+1],r,c+1});
            }
            //left
            if(c-1>=1&&dis[r][c-1]>d+horizontal[r][c-1]){
                dis[r][c-1]=d+horizontal[r][c-1];
                q.push({dis[r][c-1],r,c-1});
            }
        }
        int ans=inf32;
        for(int i=0;i<=K;++i){
            for(int j=1;j<=K+1;++j){
                if(i==0||i==K||j==1||j==K+1){
                    ans=min(ans,dis[i][j]);
                }
            }
        }
        printf("%d\n",N-ans);
    }
}   