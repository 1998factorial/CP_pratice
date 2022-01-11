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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll N,K,X;
        cin>>N>>K>>X;
        string a;
        cin>>a;
        vector<int>len;
        int c=0,pre=-1;
        vector<pii>pos;
        for(int i=0;i<N;++i){
            if(a[i]=='*'){
                c+=1;
                if(pre==-1)pre=i;
            }
            else{
                if(c){
                    len.push_back(c*K);
                    pos.push_back({pre,i-1});
                }
                c=0;
                pre=-1;
            }
        }
        if(c){
            len.push_back(c*K);
            pos.push_back({pre,N-1});
        }
        int sz=len.size(),found=0;
        vector<long double>v(sz+1,0);
        v[sz]=1;
        for(int i=sz-1;i>=0;--i){
            v[i]=v[i+1]*(1+len[i]);
        }
        //try to construct prefix
        vector<int>num(sz,0);
        for(int i=0;i<sz;++i){
            for(int j=0;j<=len[i];++j){
                if(X>v[i+1]){
                    X-=v[i+1];
                }
                else{
                    num[i]=j;
                    break;
                }
            }
        }
        string ans="";
        int id=0;
        c=-1;
        for(int i=0;i<N;++i){
            if(a[i]=='a'){
                if(c!=-1){
                    for(int j=0;j<num[id];++j)ans+='b';
                    ++id;
                }
                c=-1;
                ans+='a';
            }
            else{
                c=1;
            }
        }
        if(c!=-1){
            for(int j=0;j<num[id];++j)ans+='b';
        }
        cout<<ans<<endl;
    }
}   