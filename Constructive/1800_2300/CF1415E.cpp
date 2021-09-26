#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
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
const int mod = 1e9 + 7;
int N , K;
// this problem is about constructing the optimal base
// then build/enumerate on that
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    vector<int> a(N);
    for(int i = 0; i < N; ++i)cin >> a[i];
    sort(a.begin() , a.end());
    ll ans = 0;
    // put all elements into one sub game
    for(int i = 0; i < N; ++i){
        ans += (ll)a[i] * i;
    }
    vector<ll> sum(N + 1) , wsum(N + 1);
    for(int i = 1; i <= N; ++i){
        sum[i] = sum[i - 1] + a[i - 1];
        wsum[i] = wsum[i - 1] + (ll)a[i - 1] * i;
    }
    ll total_base_val = 0;
    int cur = 0 , max_sz = 0;
    vector<vector<int>> vec(K + 1);
    for(int len = 1; len <= N; ++len){
        // distribute the first len elements evenly in 
        // k + 1 sub games
        // add the remaining N - len elements into the largest
        // sub game
        total_base_val += (ll)a[len - 1] * vec[cur].size();
        vec[cur].push_back(a[len - 1]);
        max_sz = max(max_sz , (int)vec[cur].size());
        cur = (cur + 1) % (K + 1);
        ll inc = 0;
        //for(int j = len , k = 0; j < N; ++j , ++k){
        //    inc += (ll)a[j] * (max_sz + k);
        //}
        inc += (sum[N] - sum[len]) * max_sz;
        inc += wsum[N] - wsum[len];
        inc -= (sum[N] - sum[len]) * (len + 1); 
        ans = max(ans , inc + total_base_val);
    }
    cout << ans << endl;
} 