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
const int maxv = 2e7 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 1;
ll add(ll x , ll y){
    return (x + y) % mod;
}
int N;
ll delta[1000] , T[1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ans = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> T[i];
        for(int j = 0; j < 1000; ++j){
            if(delta[j] + j > T[i])--delta[j];
            if(delta[j] + j < T[i])++delta[j];
        }
        int sz;
        cin >> sz;
        for(int j = 1; j <= sz; ++j){
            int x;
            cin >> x;
            x = add(x , ans);
            ans = (delta[x] + x);
            cout << ans << endl;
        }
    }
}