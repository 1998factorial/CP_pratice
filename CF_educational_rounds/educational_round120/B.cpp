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
        int N;
        cin>>N;
        vector<int>p(N);
        for(int i=0;i<N;++i)cin>>p[i];
        string s;
        cin>>s;
        vector<int>id(N);
        for(int i=0;i<N;++i)id[i]=i;
        sort(id.begin(),id.end(),[&](int& l,int& r){
            if(s[l]>s[r])return 1;
            if(s[l]==s[r]&&p[l]>p[r])return 1;
            return 0;
        });
        int c=N;
        vector<int>ans(N);
        for(auto i:id){
            ans[i]=c;
            --c;
        }
        for(int i:ans)cout<<i<<" ";
        cout<<endl;
    }
}