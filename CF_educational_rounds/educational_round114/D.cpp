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
map<vector<int>,int>ban,vis;
int N,sz[15],M;
vector<int>a[15];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>sz[i];
        for(int j=0;j<sz[i];++j){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    cin>>M;
    for(int i=0;i<M;++i){
        vector<int>tmp;
        for(int j=0;j<N;++j){
            int x;
            cin>>x;
            --x;
            tmp.push_back(x);
        }
        ban[tmp]=1;
    }
    int max_val=0;
    vector<int>ans;
    queue<vector<int>>q;
    for(int i=0;i<N;++i)ans.push_back(sz[i]-1);
    q.push(ans);
    while(!q.empty()){
        auto vec=q.front();
        q.pop();
        if(vis[vec]){
            continue;
        }
        vis[vec]=1;
        if(ban[vec]==0){
            int val=0;
            for(int i=0;i<N;++i){
                val+=a[i][vec[i]];
            }
            if(val>max_val){
                max_val=val;
                ans=vec;
            }
            continue;
        }
        for(int i=0;i<N;++i){
            if(vec[i]>0){
                vector<int>tmp=vec;
                tmp[i]--;
                if(vis[tmp]==0)q.push(tmp);
            }
        }
    }
    for(int i:ans)cout<<i+1<<" ";
    cout<<endl;
}   