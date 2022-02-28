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
const int mod = 998244353;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    int t=1;
    printf("%d\n",t);
    while(t--){
        int N=1e5,M=1e5,K=1e5;
        printf("%d %d %d\n",N,M,K);
        for(int i=1;i<=K;++i){
            int a=gen()%N+1,b=gen()%M+1,c=gen()%N+1,d=gen()%M+1,h=gen()%N+1;
            if(a>c)swap(a,c);
            printf("%d %d %d %d %d\n",a,b,c,d,h);
        }
    }
}