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
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int tree[maxn << 2],N;
ll ask(int pos){
    if(pos<0)return 0;
    ll ans=0;
    while(pos){
        ans+=tree[pos];
        pos-=pos&(-pos);
    }
    return ans;
}
void update(int pos,int val){
    while(pos<=N){
        tree[pos]+=val;
        pos+=pos&(-pos);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>N;
        string a,b,c;
        cin>>a;
        cin>>b;
        c=a;
        sort(c.begin(),c.end());
        if(c>=b){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<=N*4;++i)tree[i]=0;
        for(int i=1;i<=N;++i)update(i,1);
        ll ans=inf64,sum=0;
        vector<int>pos[26],ptr(26);
        for(int i=0;i<N;++i)pos[a[i]-'a'].push_back(i+1);
        for(int prefix=1;prefix<=N;++prefix){
            // use fenwick tree to maintain the state of the current string
            for(int c=0;c<b[prefix-1]-'a';++c){
                if(ptr[c]>=pos[c].size())continue;
                ans=min(ans,sum+ask(pos[c][ptr[c]]-1));
            }
            int c=b[prefix-1]-'a';
            if(ptr[c]>=pos[c].size())break;
            sum+=ask(pos[c][ptr[c]]-1);
            update(pos[c][ptr[c]],-1);
            ++ptr[c];
        }   
        cout<<ans<<endl;
    }
}