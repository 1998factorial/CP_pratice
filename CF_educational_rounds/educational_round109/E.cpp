#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 998244353;

ll add(ll x , ll y){
    return (x + y) % mod;
}

ll mul(ll x , ll y){
    return x * y % mod;
}

ll sub(ll x , ll y){
    x -= y;
    x %= mod;
    if(x < 0)x += mod; 
    return x;
}

ll qpow(ll x , ll n){
    if(n <= 0)return 1;
    ll ret = qpow(x , n / 2);
    ret = mul(ret , ret);
    if(n & 1)ret = mul(ret , x);
    return ret;
}
    
ll inverse(ll x){
    return qpow(x , mod - 2);
}

int N , M , d[21][50005];
ll f[25];

ll solve(int col){
    vector<int> vec;
    for(int i = 1; i <= N; ++i)vec.push_back(d[i][col]);
    sort(vec.begin() , vec.end());
    ll ans = 1;
    // 1 2 ... N
    // d[i][j] = 2 , can not put at Nth turn , 2 - 1 choice
    // d[i + 1][j] = 3 , can not put at Nth, N-1th turn , 3 - 2 choice
    for(int i = 0; i < N; ++i){
        ans = mul(ans , max(0ll , (ll)vec[i] - (i + 1)));
    }
    ans = sub(f[N] , ans);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> d[i][j];
        }
    }
    ll ans = 0 , down = 1;
    f[0] = 1;
    for(int i = 1; i <= 20; ++i)f[i] = mul(f[i - 1] , i);
    for(int i = 1; i <= M; ++i){
        ans = add(ans , solve(i));
    }
    ans = mul(ans , inverse(f[N]));
    cout << ans << endl;
}