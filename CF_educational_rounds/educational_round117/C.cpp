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

ll get_val(ll pos , ll k){
    if(pos <= k){
        return (pos + 1) * pos / 2; 
    }
    ll ans = (k + 1) * k / 2;
    pos -= k;
    ans += (k) * (k - 1) / 2 - (k - pos) * (k - 1 - pos) / 2; 
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll k , x , ans = 0;
        cin >> k >> x;
        ll l = 0 , r = k * 2 - 1;
        while(l <= r){
            ll mid = (l + r) / 2;
            if(get_val(mid , k) >= x){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(ans == 0)ans = k * 2 - 1;
        cout << ans << endl;
    }
}