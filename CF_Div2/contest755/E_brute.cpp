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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        // even pos sum = odd pos sum is the winning condition
        // also, 0 should not be a edge case to check
        int N;
        cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        ll ans = 0;
        for(int r = 0 , f = 1; r < N; ++r , f = 1){
            for(int l = r; l >= 0 && f != 0; --l){
                ll v = a[r];
                int ok = 1;
                for(int i = r - 1; i >= l; --i){
                    if(v > a[i]){
                        ok = 0;
                        f = 0;
                        break;
                    }
                    v = a[i] - v;
                }
                if(v)ok = 0;
                ans += ok;
            }
        }
        cout << ans << endl;
    }
}