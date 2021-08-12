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
const int maxn = 1e6 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        ll ans = 0;
        N -= 6;
        ans += 15;
        if(N > 0){
            ans += (N / 2 + N % 2) * 5;
        }
        cout << ans << endl;
    }
}   
