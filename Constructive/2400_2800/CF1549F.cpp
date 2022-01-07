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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
void solve(ll s , ll n , ll k){
    if(s == k){
        cout << "YES" << endl;
        return ;
    }
    if(s < k){
        cout << "NO" << endl;
        return ;
    }
    ll nblock = s / k;
    ll max_len = 0;
    ll rem = s % k;
    if(nblock % 2 == 1){
        // for 0 , k , 2k , 3k , ...
        // we can not take k
        // so we take 3k , 5k , ... 
        max_len = k * ((nblock + 1) / 2) - 1;
    }
    else{
        max_len = k * (nblock / 2) + rem;
    }
    if(max_len >= n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    //cout << "max_len = " << max_len << endl;
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll s , n , k;
        cin >> s >> n >> k;
        solve(s , n , k);
    }
} 