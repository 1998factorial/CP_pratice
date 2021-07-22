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
const ll mod = 998244353;
/*
    A very hard problem https://codeforces.com/contest/1546/problem/E
    Given a 2N by N matrix, we need to find the number of 
    ways to select N rows to make a latin square (幻方)
    Also given:
        a. we can make at least one latin square
        b. each row will "clash" with at least one other row
        c. No 2 rows are identical
    Call the N rows that can make latin square "original" rows
    The other N rows are additional rows.
    Observations:
    1. If a row has a number that only appears exactly once in its column in the matrix
    then this row must be an original row (If not then it contradicts with the given 
    condition that we can make a latin square)
    2. All rows with (1) condition need to be selected. (If not, we can not make a latin square)
    3. If we have x original rows selected, then we are going to eliminate at least x additional rows
    4. If we are left with no rows that satisfy (1), then all numbers in these rows appear exactly 2 times.
    Why? Since occurences of each number is greater than 1, so for 0 <= x <= N - 1 , cnt[x] >= 2
    Say we have selected x rows, then we must have eliminated at least 2x rows
    so if we have M rows left, M <= 2N - 2x
    for each number x in [0 , N - 1], on each column, sum{cnt[x]} = M
    
*/
ll mul(ll x , ll y){
    return (x * y) % mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<vector<int>> a(2 * N , vector<int>(N));
        for(int i = 0; i < 2 * N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> a[i][j];
                --a[i][j];
            }
        }

    }
}   
