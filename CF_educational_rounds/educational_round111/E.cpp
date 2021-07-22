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
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , K;
char a[maxn];
int nex[maxn][17] , dp[1 << 17];
bool check(int mid){
    for(int i = 1; i <= N + 1; ++i){
        for(int j = 0; j < K; ++j){
            nex[i][j] = inf32;
        }
    }
    for(int j = 0; j < K; ++j){
        int len = 0;
        for(int i = N; i >= 1; --i){
            if(a[i] == '?' || a[i] - 'a' == j){
                ++len;
                if(len >= mid){
                    nex[i][j] = min(nex[i][j] , i + mid - 1);
                }
            }
            else{
                len = 0;
            }
            nex[i][j] = min(nex[i][j] , nex[i + 1][j]);
        }
    }
    for(int mask = 0; mask < 1 << K; ++mask){
        dp[mask] = inf32;
    }
    dp[0] = 0;
    for(int mask = 0; mask < 1 << K; ++mask){
        if(dp[mask] >= inf32)continue;
        for(int j = 0; j < K; ++j){
            if(mask >> j & 1)continue;
            int nmask = mask ^ (1 << j);
            int start = dp[mask] + 1;
            if(nex[start][j] < inf32)dp[nmask] = min(dp[nmask] , nex[start][j]);
        }
    }
    return dp[(1 << K) - 1] <= N;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    cin >> (a + 1);
    int l = 0 , r = N , ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << endl;
}   
// we can binary search answer
// so our question is: can we have a construction such that each characters 
// have contigious subsequence of length K?
// we can ask a weaker question: given an order of completion , eg, {do 'a' , then 'c', lastly 'b'}
// is there a way for us to check if this order works?
// we can solve this by a greedy idea: always finish the current character blocks as early as possible.
// so for each position i, and character c, we compute the smallest j, such that we can construct a length of 
// K block of c's in a[i...j]. (One can see that, if there exists an optimal solution that 
// can build a block of c's in a[i...j + x] , then it will be even better to finish within a[i...j])
// so given an ordering, we can check if it is fessible, but that will be O(logN * (N * K + K! * K)) , K <= 17 , too slow
// but fixing ordering is just a variation of Travelling sales man problem (TSP)
// we can speed this up by DP