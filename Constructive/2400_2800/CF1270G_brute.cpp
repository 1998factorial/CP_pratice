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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int N;
        scanf("%d",&N);
        vector<int>a(N+1),b(N+1);
        for(int i=1;i<=N;++i){
            scanf("%d",&a[i]);
            b[i]=i-a[i];
        }
        set<int>S;
        for(int i=1;i<=N;++i)S.insert(b[i]);
        for(;;){
            set<int>nS;
            for(int i:S)nS.insert(b[i]);
            if(nS==S)break;
            S=nS;
        }
        printf("%d\n",(int)S.size());
        for(int i:S)printf("%d ",i);
        printf("\n");
    }
}   