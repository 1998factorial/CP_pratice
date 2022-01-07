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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
ll gcd(ll x , ll y){
    return x == 0 ? y : gcd(y % x , x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll x , y;
        cin >> x >> y;
        if(x == y){
            cout << x << endl;
            continue;
        }
        if(x > y){
            cout << x + y << endl;
            continue;
        }
        if(y % x == 0){
            cout << x << endl;
            continue;
        }
        cout << y - (y % x) / 2 << endl;
        /*vector<int> ans;
        for(ll n = 1; n <= 1e7; ++n){
            if(n % x == y % n)ans.push_back(n);
        }
        cout << "show answer ";
        for(auto i : ans){
            if(i > y * 2)break;
            cout << i << " ";
        }
        cout << endl;*/
    }
} 