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
char a[300005];
int N,Q;
ll ending[300005],sum[300005];
int main(){
    scanf("%d%d",&N,&Q);
    scanf("%s",a+1);
    vector<int>st;
    for(int i=1;i<=N;++i){
        if(a[i]=='('){
            st.push_back(i);
        }
        else if(!st.empty()){
            ending[i]+=ending[st.back()-1]+1;
            st.pop_back();
        }
        sum[i]+=sum[i-1]+ending[i];
    }
    while(Q--){
        int t,L,R;
        scanf("%d%d%d",&t,&L,&R);
        printf("%lld\n",sum[R]-sum[L-1]-(ending[L-1]*(ending[R]-ending[L-1])));
    }
}   
