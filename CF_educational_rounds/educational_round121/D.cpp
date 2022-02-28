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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,N;
    cin>>t;
    while(t--){
        cin>>N;
        vector<ll>s(N+1);
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            ++s[x];
        }
        for(int i=1;i<=N;++i){
            s[i]+=s[i-1];
        }
        int up=ceil(log2(N))+1;
        int ans=inf32;
        for(int x=0;x<=up;++x){
            for(int y=0;y<=up;++y){
                for(int z=0;z<=up;++z){
                    int A=1<<x,B=1<<y,C=1<<z;
                    if(A+B+C<N)continue;
                    int l=1,r=N,a=0,b=0,c=0,d=0;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(s[mid]-s[a]<=A){
                            b=mid;
                            l=mid+1;
                        }
                        else{
                            r=mid-1;
                        }
                    }
                    l=b,r=N;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(s[mid]-s[b]<=B){
                            c=mid;
                            l=mid+1;
                        }
                        else{
                            r=mid-1;
                        }
                    }
                    if(s[N]-s[c]>C)continue;
                    int val=0;
                    val+=A-(s[b]-s[a]);
                    val+=B-(s[c]-s[b]);
                    val+=C-(s[N]-s[c]);
                    ans=min(ans,val);
                }
            }
        }
        cout<<ans<<endl;
    }
}   