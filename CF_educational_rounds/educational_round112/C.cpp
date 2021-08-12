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
        int M;
        cin >> M;
        vector<vector<int>> a(2 , vector<int>(M));
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < M; ++j){
                cin >> a[i][j];
            }
        }
        vector<vector<ll>> sum(2 , vector<ll>(M));
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < M; ++j){
                if(j > 0)sum[i][j] += sum[i][j - 1];
                sum[i][j] += a[i][j];
            }
        }
        ll ans = inf64;
        for(int i = 0; i < M; ++i){
            ll v = sum[0][M - 1] - sum[0][i];
            if(i - 1 >= 0)v = max(v , sum[1][i - 1]);
            ans = min(ans , v);
        }
        cout << ans << endl;
    }
}   
