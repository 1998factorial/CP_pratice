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
const int M=10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q=50,N=10,M=10;
    cout<<N<<" "<<M<<" "<<q<<endl;
    while(q--){
        int c=gen()%3;
        int x=gen()%N+1,y=gen()%M+1;
        cout<<x<<" "<<y<<" "<<c-1<<endl;
    }
}