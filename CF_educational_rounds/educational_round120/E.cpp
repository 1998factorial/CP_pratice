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
        int N,M;
        cin>>N>>M;
        vector<int>X(N);
        for(int i=0;i<N;++i)cin>>X[i];
        vector<string>a(N);
        for(int i=0;i<N;++i)cin>>a[i];
        vector<int>ans;
        vector<int>p(M),q(M);
        for(int i=0;i<M;++i)p[i]=i;
        int max_score=-1;
        for(int mask=0;mask<1<<N;++mask){
            //1->"-",0->"+"
            int val=0;
            for(int i=0;i<N;++i){
                if(mask>>i&1)val-=X[i];
                else val+=X[i];
            }
            vector<int>v(M);
            for(int i=0;i<M;++i){
                for(int j=0;j<N;++j){
                    if(a[j][i]=='0')continue;
                    if(mask>>j&1)++v[i];
                    else --v[i];
                }
            }
            sort(p.begin(),p.end(),[&](int& l,int& r){
                return v[l]<v[r];
            });
            for(int i=0;i<M;++i){
                val+=v[p[i]]*(i+1);
            }
            for(int i=0;i<M;++i){
                q[p[i]]=i;
            }
            if(val>max_score){
                max_score=val;
                ans=q;
            }
        }
        for(int i:ans)cout<<i+1<<" ";
        cout<<endl;
    }
}