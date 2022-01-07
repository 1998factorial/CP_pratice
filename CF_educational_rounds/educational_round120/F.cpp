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
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
vector<int> factor[maxv];
bool vis[maxv];
unsigned long long H[maxv];
map<int,unsigned long long> mp;
map<unsigned long long,int> rmp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=2;i<=N;++i){
        if(vis[i])continue;
        mp[i]=gen(); // give a hashed value to each prime
        for(int j=i;j<=N;j+=i){
            vis[j]=true;
            factor[j].push_back(i);
        }
        //cerr<<"mp["<<i<<"]="<<mp[i]<<endl;
    }
    for(int i=2;i<=N;++i){
        H[i]=H[i-1];  // Hash value of (i!)
        int v=i;
        for(int p:factor[i]){
            while(v%p==0){
                v/=p;
                H[i]^=mp[p];
            }
        }
        rmp[H[i]]=i;
    }
    unsigned long long total=0;
    for(int i=2;i<=N;++i)total^=H[i];
    if(total==0){ // answer is N
        cout<<N<<endl;
        for(int i=1;i<=N;++i)cout<<i<<" ";
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=N;++i){
        if(total==H[i]){ // answer is N-1
            cout<<N-1<<endl;
            for(int j=1;j<=N;++j){
                if(j!=i)cout<<j<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    for(int i=2;i<=N;++i){
        unsigned long long val=total^H[i];
        // check if exists H[j]=val
        if(rmp.count(val)>0&&rmp[val]!=i){
            cout<<N-2<<endl;
            for(int j=1;j<=N;++j){
                if(j!=i&&j!=rmp[val])cout<<j<<" ";
            }   
            cout<<endl;
            return 0;
        }
    }
    //answer in the worst case is N-3
    cout<<N-3<<endl;
    for(int i=1;i<=N;++i){
        if(i!=2&&i!=N&&i!=(N-1)/2)cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}