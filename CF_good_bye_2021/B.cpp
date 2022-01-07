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
    cin>>t;
    while(t--){
        string s;
        int N;
        cin>>N;
        cin>>s;
        if(N==1){
            cout<<s[0]<<s[0]<<endl;
            continue;
        }
        if(s[0]<=s[1]){
            cout<<s[0]<<s[0]<<endl;
            continue;
        }
        int index=1;
        while(index<N&&s[index]<=s[index-1])++index;
        for(int i=0;i<index;++i)cout<<s[i];
        for(int i=index-1;i>=0;--i)cout<<s[i];
        cout<<endl;
    }
}