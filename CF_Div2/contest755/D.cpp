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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
ll query(int l , int r){
    cout << "? " << l << " " << r << endl;
    cout.flush();
    ll ret;
    cin >> ret;
    return ret;
}
void answer(int i , int j , int k){
    cout << "! " << i << " " << j << " " << k << endl;
    cout.flush();
}
// think about prefix sum
// [3 , 2 , 1] for inversion delta [2 , 1 , 0]
// inv[i , j] - inv[i + 1 , j] = j - i
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll total = query(1 , n);
        int l = 1 , r = n , i = 1;
        // find i with log(N) queries
        while(l <= r){
            int mid = (l + r) / 2;
            if(query(1 , mid) == 0){
                i = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        int j = total - query(i + 1 , n) + i + 1;
        int k = total - query(i , j - 1) - query(j + 1 , n) + j;
        answer(i , j , k);
    }
}