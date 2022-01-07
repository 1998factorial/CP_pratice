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
bool check(const vector<ll>& a , ll mid , ll H){
    ll dmg = 0 , pre = a[0];
    for(int i = 1; i < a.size(); ++i){
        ll diff = a[i] - a[i - 1];
        diff = min(diff , mid);
        dmg += diff;
    }
    dmg += mid;
    return dmg >= H;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll N , H;
        cin >> N >> H;
        vector<ll> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        ll l = 0 , r = H , ans = H;
        while(l <= r){
            ll mid = (l + r) / 2;
            if(check(a , mid , H)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << endl;
    }
}