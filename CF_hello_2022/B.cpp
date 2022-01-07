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
const int maxn = 2e5 + 10;
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
        int N;
        cin>>N;
        vector<array<ll,3>> vec(N);
        for(int i=0;i<N;++i){
            cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
        }
        ll ans=inf64;
        map<ll,set<ll,ll>>l,r;
        map<ll,set<ll>>lv,rv;
        set<ll> v;
        for(int i=0;i<N;++i){
            l[vec[i][0]].insert({vec[i][2],(ll)i});
            r[vec[i][1]].insert({vec[i][2],(ll)i});
            lv[vec[i][0]].insert((ll)i);
            rv[vec[i][1]].insert((ll)i);
            if(!v.empty()&&vec[i][0]<=)

            v.insert(vec[i][0]);
            v.insert(vec[i][1]);
        }
    }
}