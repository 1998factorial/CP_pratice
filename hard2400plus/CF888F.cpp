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
const int maxn = 510;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const int mod = 1e9 + 7;
int mul(int x , int y){
    return (ll)x * y % mod;
}
int add(int x , int y){
    ll ret = x;
    ret += y;
    if(ret >= mod)ret -= mod;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1 , vector<int>(N + 1));
    vector<vector<int>> f(N + 1 , vector<int>(N + 1)) , g(N + 1 , vector<int>(N + 1));
    // f[i][j] = the number of ways to make vertices i..j into a tree
    // g[i][j] = the number of ways to make vertices i..j into a tree given i and j are linked directly
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < N; ++i)f[i][i] = g[i][i] = 1;
    for(int len = 2; len <= N; ++len){
        for(int i = 0; i + len - 1 < N; ++i){
            int j = i + len - 1;
            for(int k = i; k < j; ++k){
                if(a[i][j]){
                    // since i and j are linked directly
                    // we must divide [i..j] into [i..k] and [k+1..j] 
                    // if we don't we will either have a cycle or crossing edges
                    // so we have f[i][k] * f[k + 1][j] for each k
                    g[i][j] = add(g[i][j] , mul(f[i][k] , f[k + 1][j]));
                }
            }
            for(int k = i + 1; k <= j; ++k){
                if(a[i][k]){    
                    // the total number of ways of making [i..j] into a tree 
                    // i must link directly to some k in [i+1..j] and 
                    // now we have g[i][k] * f[k][j] as this contribution
                    f[i][j] = add(f[i][j] , mul(g[i][k] , f[k][j]));
                }
            }
        }
    }
    cout << f[0][N - 1] << endl;    
}       