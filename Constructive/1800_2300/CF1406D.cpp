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
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int N , Q;
ll a[maxn] , d[maxn] , tree[maxn << 2];
void update(int pos , ll v){
    while(pos <= N){
        tree[pos] += v;
        pos += pos & (-pos);
    }
}
ll query(int pos){
    ll ans = 0;
    while(pos){
        ans += tree[pos];
        pos -= pos & (-pos);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i < N; ++i){
        d[i] = a[i + 1] - a[i];
        update(i , max(d[i] , 0ll));
    }
    ll sum = query(N - 1);
    ll X = (a[1] + sum) / 2;
    cout << max(X , a[1] - X + sum) << endl;
    cin >> Q;
    while(Q--){
        int l , r , x;
        cin >> l >> r >> x;
        if(l == 1 || r == 1)a[1] += x;
        if(l - 1 >= 1){
            update(l - 1 , -max(0ll , d[l - 1]));
            d[l - 1] += x;
            update(l - 1 , max(0ll , d[l - 1]));
        }
        if(r < N){
            update(r , -max(0ll , d[r]));
            d[r] -= x;
            update(r , max(0ll , d[r]));
        }
        sum = query(N - 1);
        X = (a[1] + sum) / 2;
        cout << max(X , a[1] - X + sum) << endl;
    }
} 