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
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        sort(a.begin() , a.end());
        set<int> v;
        for(int i = 1; i <= N; ++i)v.insert(i);
        int ans = 0 , good = 1;
        for(int i = 0; i < N; ++i){
            if(a[i] < 1){
                good = 0;
                break;
            }
            if(v.count(a[i])){
                v.erase(a[i]);
                continue;
            }
            auto it = v.begin();
            if(*it < (a[i] + 1) / 2){
                ++ans;
                v.erase(*it);
            }
            else{
                good = 0;
                break;
            }
        }
        if(good)cout << ans << endl;
        else cout << -1 << endl;
    }
}