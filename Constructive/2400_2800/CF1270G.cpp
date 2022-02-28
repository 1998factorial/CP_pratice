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
vector<int>g[maxn],st;
int dfn[maxn],low[maxn],cnt;
bool instack[maxn];
vector<vector<int>> ans;
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
void tarjan(int v){
    st.push_back(v);
    instack[v]=1;
    dfn[v]=low[v]=++cnt;
    for(int nv:g[v]){
        if(dfn[nv]==0){
            tarjan(nv);
            low[v]=min(low[v],low[nv]);
        }
        else if(instack[nv]){
            low[v]=min(low[v],dfn[nv]);
        }
    }
    if(low[v]==dfn[v]){
        vector<int>tmp;
        while(st.back()!=v){
            tmp.push_back(st.back());
            st.pop_back();
        }
        tmp.push_back(st.back());
        st.pop_back();
        ans.push_back(tmp);
    }
}
int main(){
    int t;
    t=read();
    while(t--){
        int N;
        N=read();
        vector<int>a(N+1),b(N+1);
        cnt=0;
        for(int i=1;i<=N;++i){
            a[i]=read();
            b[i]=i-a[i];
        }
        int ok=0;
        for(int i=1;i<=N;++i){
            if(b[i]==i){
                ok=1;
                printf("1\n%d\n",i);
                break;
            }
        }
        if(ok)continue;
        for(int i=1;i<=N;++i){
            g[i].push_back(b[i]);
        }
        for(int i=1;i<=N;++i){
            if(dfn[i]==0&&ans.empty()){
                tarjan(i);
            }
        }
        for(auto&e:ans){
            printf("%d\n",(int)e.size());
            for(auto&i:e){
                printf("%d ",i);
            }
            printf("\n");
            break;
        }
        for(int i=1;i<=N;++i){
            g[i].clear();
            dfn[i]=low[i]=instack[i]=0;
        }
        st.clear();
        ans.clear();
    }
}   