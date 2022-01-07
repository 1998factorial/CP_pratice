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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        vector<int>a(3);
        for(int i=0;i<3;++i)cin>>a[i];
        sort(a.begin(),a.end());
        int ok=0,cnt=0;
        do{
            if(a[1]==a[2]&&a[0]%2==0){
                ok=1;
            }
            if(a[0]==a[1]+a[2]){
                ok=1;
            }
        }while(next_permutation(a.begin(),a.end()));   
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}