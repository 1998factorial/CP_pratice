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
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int c[1005][1005] , sz[1005] , must[1005] , can[1005];
ld flogs[1005] , dp[1005][1005];
/*
    this question is phrased in a werid way
    What it is asking for:
    You are given M lists of integers (integers do not duplicate in each list)
    You are going to get N items (integers) from these lists
    say you want x items from list i, you are going to get x items randomly
    You want to calculate the average probability that you can get the largest N items
*/
/*
    Solution:
    If the largest N integers are all different, then the answer is just
    1 / (C(sz[1] , cnt[1]) *..* C(sz[M] , cnt[M]))
    It gets different when we have many items = the N-th largest item
    say we have y = Nth item and we have k items > Nth and we need N - k items 
    from y of them.
    then the answer for this case should be:
    (sum of the probability that we get N - k items = Nth) / (the number of ways of selecting N - k from y)
    which is top / C(y , N - k)
    to calculate top, we can use dp
    let dp[i][j] = the probability if we have selected j items = Nth from the first i lists.
    dp[i][j] += dp[i - 1][j] / C(sz[i] , #item > Nth) if we do not select one from ith list
    dp[i][j] += dp[i - 1][j - 1] / C(sz[i] , #item >= Nth) if we do
    notice that lists have distinct elements so 0 <= (item >= Nth) - (item > Nth) <= 1
    then answer is just dp[M][N - k] / C(y , N - k)
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , M;
    vector<int> tmp;
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        cin >> sz[i];
        for(int j = 1; j <= sz[i]; ++j){
            cin >> c[i][j];
            tmp.push_back(c[i][j]);
        }
    }
    sort(tmp.rbegin() , tmp.rend());
    set<int> topn;
    for(int i = 0; i < N; ++i){
        topn.insert(tmp[i]);
    }
    int smallest = *topn.begin() , ngreater = 0 , n_equal_take = 0 , nequal = 0;
    for(int i = 1; i <= M; ++i){
        must[i] = can[i] = 0;
        for(int j = 1; j <= sz[i]; ++j){
            if(c[i][j] > smallest)++must[i];
            else if(c[i][j] == smallest)++can[i];
        }
        nequal += can[i];
        ngreater += must[i];
    }
    n_equal_take = N - ngreater;
    for(int i = 1; i < 1005; ++i){
        flogs[i] = flogs[i - 1] + log(1.0 * i);
    }
    auto C = [&](int n , int m) -> ld {
        return exp(flogs[n] - flogs[n - m] - flogs[m]);
    };
    dp[0][0] = 1.0;
    for(int i = 1; i <= M; ++i){
        for(int j = 0; j <= n_equal_take; ++j){
            if(can[i] > 0){
                if(j > 0){
                    dp[i][j] = dp[i - 1][j] / C(sz[i] , must[i]) + dp[i - 1][j - 1] / C(sz[i] , must[i] + 1);
                }
                else{
                    dp[i][j] = dp[i - 1][j] / C(sz[i] , must[i]);
                }
            }
            else{
                dp[i][j] = dp[i - 1][j] / C(sz[i] , must[i]);
            }
        }
    }
    ld ans = dp[M][n_equal_take] / C(nequal , n_equal_take);
    cout << setprecision(12) << ans << endl;
}   
