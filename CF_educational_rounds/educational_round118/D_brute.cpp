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
const int maxv = 2e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const ll mod = 998244353;
ll add(ll x , ll y){
    return (x + y) % mod;
}
ll mul(ll x , ll y){
    return x * y % mod;
}
int mex(vector<int> a){
    set<int> v;for(int i : a)v.insert(i);
    for(int i = 0; ;++i)if(v.count(i)==0)return i;
}
// start with 0
// we can append 0 or 1
// start with 1, we can only append 1

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        ll ans = 0;
        for(int mask = 1; mask < 1 << N; ++mask){
            vector<int> b;
            for(int i = 0; i < N; ++i)if(mask >> i & 1)b.push_back(a[i]);
            int ok = 1;
            vector<int> c;
            for(int i = 0; i < b.size(); ++i){
                c.push_back(b[i]);
                if(abs(mex(c) - b[i]) > 1)ok = 0;
            }
            if(ok){
                ++ans;
                cout<<"good: ";
                for(int i : b)cout << i << " ";
                cout<<endl;
            }
        }
        cout << ans << endl;
    }
}