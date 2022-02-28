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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        vector<int>cnt(26);
        for(int i=0;i<a.size();++i)cnt[a[i]-'a']++;
        string ans="";
        for(int i=0;i<26;++i){
            if(cnt[i]==2)ans+='a'+i,ans+='a'+i;
            if(cnt[i]==1)ans+='a'+i;
        }
        cout<<ans<<endl;
    }
}   