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
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int N,M;
        cin>>N>>M;
        if(M>(N+1)/2)cout<<-1<<endl;
        else{
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(i==j&&i%2==0&&M){
                        cout<<'R';
                        --M;
                    }
                    else{
                        cout<<'.';
                    }
                }
                cout<<endl;
            }
        }
    }
}