#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxn = 510;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , P , K;
    cin >> N >> P >> K;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i)cin >> a[i];
    vector<ll> b(N);
    map<ll , ll> cnt;
    auto sub = [&](ll x , ll y) -> ll {
        x -= y;
        if(x < 0)x += P;
        return x;
    };
    auto mul = [&](ll x , ll y) -> ll {
        return x * y % P;
    };
    for(int i = 0; i < N; ++i){
        b[i] = sub(mul(mul(a[i] , a[i]) , mul(a[i] , a[i])) , mul(a[i] , K));
        cnt[b[i]]++;
    }    
    ll ans = 0;
    for(auto& e : cnt){
        ans += e.y * (e.y - 1) / 2;
    }
    cout << ans << endl;
}       
