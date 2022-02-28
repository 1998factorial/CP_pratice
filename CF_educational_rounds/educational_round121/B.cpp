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
        //try 2 digit
        int pos=-1,sz=a.size();
        for(int i=0;i+1<sz;++i){
            int v=(a[i]-'0')+(a[i+1]-'0');
            if(v>=10){
                pos=i;
            }
        }
        if(~pos){
            string ans="";
            for(int i=0;i<pos;++i)ans+=a[i];
            int v=(a[pos]-'0')+(a[pos+1]-'0');
            ans+='0'+1;
            ans+='0'+(v%10);
            for(int i=pos+2;i<sz;++i)ans+=a[i];
            cout<<ans<<endl;
            continue;
        }
        //try 1 digit
        for(int i=0;i+1<sz;++i){
            int v=(a[i]-'0')+(a[i+1]-'0');
            if(v>=a[i+1]-'0'){
                pos=i;
                break;
            }
        }
        if(~pos){
            string ans="";
            for(int i=0;i<pos;++i)ans+=a[i];
            int v=(a[pos]-'0')+(a[pos+1]-'0');
            ans+='0'+v;
            for(int i=pos+2;i<sz;++i)ans+=a[i];
            cout<<ans<<endl;
            continue;
        }
        string ans="";
        for(int i=0;i<sz-2;++i)ans+=a[i];
        int v=(a[sz-2]-'0')+(a[sz-1]-'0');
        ans+='0'+v;
        cout<<ans<<endl;
    }
}   