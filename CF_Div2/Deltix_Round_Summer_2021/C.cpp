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
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<ll> a(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    ll ans = 0;
    for(int i = 1; i + 1 <= N; i += 2){
        ans += min(a[i] , a[i + 1]);
        if(a[i] < a[i + 1])continue;
        ll left = a[i] - a[i + 1];
        ll need_left = 0;
        for(int j = i + 2; j + 1 <= N; j += 2){
            need_left += a[j + 1] - a[j];
            if(need_left >= 0){
                ans += min(need_left , left) + 1;
                left -= need_left;
                need_left = 0;
            }
            if(left < 0)break;
        }   
    }
    cout << ans << endl;
} 

