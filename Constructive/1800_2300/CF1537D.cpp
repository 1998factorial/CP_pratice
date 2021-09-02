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
const int maxn = 2e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        if(N == 1){
            cout << "Bob" << endl;
            continue;
        }
        int v = N , cnt = 0;
        while(v % 2 == 0){
            v /= 2;
            ++cnt;
        }
        if((v > 1 && cnt > 0) || (v == 1 && cnt % 2 == 0)){
            // not a power of 2 or is an even power of 2
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
        // vector<int> dp(N + 1 , 0);
        // for(int i = 2; i <= N; ++i){
        //     for(int j = 2; j < i; ++j){
        //         if(i % j == 0){
        //             if(dp[i - j] == 0){
        //                 dp[i] = 1;
        //             }
        //         }
        //     }
            //printf("dp[%d] = %d\n" , i , dp[i]);
            //cout << dp[i];
        // }
        //cout << endl;
        //for(int i = 1; i <= N; i += 2)printf("dp[%d] = %d\n" , i , dp[i]);
    }
}