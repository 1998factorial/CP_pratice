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
const int maxn = 4e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int base = 4e5 + 10;
vector<int> pos[20][base * 2];
string a[20];
int N;
vector<vector<int>> dp;
namespace sparse_table {
    const int maxn = 4e5 + 10;
    const int inf32 = 1e9 + 10;
    int logs[maxn] , N;
    vector<int> table[20][20];
    vector<int> sz;

    int query(int id , int l , int r) {
        if(l > r)return inf32;
        int len = r - l + 1;
        int pos = r - (1 << logs[len]) + 1;
        return min(table[id][logs[len]][l] , table[id][logs[len]][pos]);
    }
    void init(int n){
        N = n;
        sz = vector<int>(n);
        for(int i = 2; i < maxn; ++i){
            logs[i] = logs[i / 2] + 1;
        }
    }
    void build(int id , vector<int> a){
        sz[id] = a.size();
        for(int i = 0; i <= logs[sz[id]]; ++i){
            table[id][i] = vector<int>(sz[id]);
        }
        for(int i = 0; i < sz[id]; ++i){
            table[id][0][i] = a[i];
        }
        for(int i = 1; i <= logs[sz[id]]; ++i){
            int prel = (1 << (i - 1));
            for(int j = 0; j < sz[id]; ++j){
                if(j + prel < sz[id]){
                    table[id][i][j] = min(table[id][i - 1][j] , table[id][i - 1][j + prel]);
                }
                else{
                    table[id][i][j] = table[id][i - 1][j];
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    sparse_table::init(N);
    vector<vector<int>> sum(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        sum[i] = vector<int>(a[i].size());
        for(int j = 0; j < a[i].size(); ++j){
            sum[i][j] += ((a[i][j] == '(') ? 1 : -1);
            if(j > 0)sum[i][j] += sum[i][j - 1];
            pos[i][base + sum[i][j]].push_back(j);
        }
        sparse_table::build(i , sum[i]);
    }
    dp = vector<vector<int>>(1 << N , vector<int>(2 , -inf32));
    dp[0][0] = 0;
    for(int mask = 0; mask < 1 << N; ++mask){
        for(int f = 0; f < 2; ++f){
            int diff = 0;
            for(int i = 0; i < N; ++i){
                if(mask >> i & 1){
                    diff += sum[i][a[i].size() - 1];
                }
            }
            if(diff < 0 && f == 0)continue;
            for(int i = 0; i < N; ++i){
                if(mask >> i & 1)continue;
                int nmask = mask ^ (1 << i);
                if(f == 1){
                    dp[nmask][f] = max(dp[nmask][f] , dp[mask][f]); // prefix is already inbalanced
                    continue;
                }
                // binary search the smallest index x in [0..a[i].size() - 1]
                // such that we have some prefix[x] < -diff
                if(sparse_table::query(i , 0 , a[i].size() - 1) < -diff){
                    // we will eventually transit to dp[nmask][1]
                    // here, we need to binary search the smallest prefix[x] < -diff
                    int l = 0 , r = a[i].size() - 1 , x = -1;
                    while(l <= r){
                        int mid = (l + r) / 2;
                        if(sparse_table::query(i , 0 , mid) < -diff){
                            x = mid;
                            r = mid - 1;
                        }
                        else{
                            l = mid + 1;
                        }
                    }
                    // then we need to binary search the largest index in
                    // pos[i][base - diff], st this index <= x
                    l = 0 , r = pos[i][base - diff].size() - 1;
                    int v = -1;
                    while(l <= r){
                        int mid = (l + r) / 2;
                        if(pos[i][base - diff][mid] < x){
                            v = mid;
                            l = mid + 1;
                        }
                        else{
                            r = mid - 1;
                        }
                    }
                    dp[nmask][f ^ 1] = max(dp[nmask][f ^ 1] , dp[mask][f] + v + 1);
                }
                else{
                    // we will not make any bad prefix here
                    // so we transit to dp[nmask][0]
                    int delta = pos[i][base - diff].size();
                    dp[nmask][f] = max(dp[nmask][f] , dp[mask][f] + delta);
                }
            }
        }
    }
    cout << max(dp[(1 << N) - 1][0] , dp[(1 << N) - 1][1]) << endl;
} 
