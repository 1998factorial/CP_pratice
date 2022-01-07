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
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
ll a[maxn];
int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        map<ll , int> cnt;
        ll S = 0;
        for(int i = 1; i <= N; ++i){
            cin >> a[i];
            S += a[i];
        }
        if((S * 2) % N != 0){
            cout << 0 << endl;
            continue;
        }
        ll ans = 0 , t = (S * 2) / N;
        for(int i = 1; i <= N; ++i){
            ans += cnt[t - a[i]];
            ++cnt[a[i]];    
        }
        cout << ans << endl;
    }
} 