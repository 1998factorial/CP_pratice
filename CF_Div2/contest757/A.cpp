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
const int maxv = 2e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , l , r , k;
        cin >> N >> l >> r >> k;
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        sort(a.begin() , a.end());
        int ans = 0;
        for(int i : a){
            if(i < l)continue;
            if(i > r)break;
            if(i > k)break;
            ans++;
            k -= i;
        }
        cout << ans << endl;
    }
}