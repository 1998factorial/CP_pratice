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
bool vis[maxn];
ll gcd(ll x , ll y){
    return x == 0 ? y : gcd(y % x , x);
}
ll lcm(ll x , ll y){
    return x * y / gcd(x , y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << lcm(69420, 42068) << endl;
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N + 1);
        int ok = 1;
        ll LCM = 2;
        for(int i = 1; i <= N; ++i){
            LCM = lcm(LCM , (ll)i + 1);
            cin >> a[i];
            if((ll)a[i] % LCM == 0)ok = 0;
        }
        if(ok)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
} 