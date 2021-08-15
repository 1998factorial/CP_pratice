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
int N , D , c[55] , dp[55 * 10000];
// s(x) + d >= s(y)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> D;
    for(int i = 1; i <= N; ++i)cin >> c[i];
    sort(c + 1 , c + 1 + N);
    dp[0] = 1;
    for(int i = 1; i <= N; ++i){
        for(int j = i * 10000; j >= 1; --j){
            if(j - c[i] >= 0){
                dp[j] |= dp[j - c[i]];
            }
        }
    }
    int max_v = 0 , min_d = 0;
    for(;;){
        int reach = max_v + D;
        while(reach >= max_v && dp[reach] == 0){
            --reach;
        }
        if(reach == max_v){
            break;
        }
        max_v = reach;
        ++min_d;
    }
    cout << max_v << " " << min_d << endl;
}   