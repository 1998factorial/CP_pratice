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
void show(ll x){
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x/=10;
    }
    reverse(v.begin() , v.end());
    for(int i : v)cout <<i;
    cout<< endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll k , x;
        cin >> k >> x;
        ll ans = 0 , s = 0;
        for(ll i = 1 , v = 1; i <= 2 * k - 1; ++i){
            s += v;
            ans = i;
            if(s >= x){
                break;
            }
            if(i < k)++v;
            else --v;
        }
        cout << ans << endl;
    }
}