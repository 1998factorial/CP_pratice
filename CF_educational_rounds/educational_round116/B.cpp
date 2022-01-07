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
        ll n , k;
        cin >> n >> k;
        // 1 + 2 + 4 + 8 + 16 + ...
        ll sum = 1 , ans = 0 , cur = 1;
        while(sum < n){
            sum += cur;
            cur *= 2ll;
            ++ans;
            if(cur > k){
                cur = k;
                break;
            }
        }
        ll remain = n - sum;
        ans += (remain + cur - 1) / cur;
        cout << ans << endl;
    }
}