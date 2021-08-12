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
ll M , K , dp[65][65][2][2];
vector<int> to_binary(ll x){
    vector<int> ans;
    while(x){
        ans.push_back(x % 2);
        x /= 2;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
ll count(ll x){
    vector<int> a = to_binary(x + 1);
    vector<int> b = to_binary(x * 2);
    if(a.size() != b.size()){
        a.insert(a.begin() , 0);
    }
    int sz = b.size();
    for(int i = 0; i <= sz; ++i){
        for(int j = 0; j <= sz; ++j){
            for(int k = 0; k < 2; ++k){
                for(int l = 0; l < 2; ++l){
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    // p => x = a
    // !p => x > a
    // q => x = b
    // !q => x < b
    dp[0][0][1][1] = 1;
    for(int i = 0; i < sz; ++i){
        for(int j = 0; j <= sz; ++j){
            for(int p = 0; p < 2; ++p){
                for(int q = 0; q < 2; ++q){
                    if(dp[i][j][p][q] == 0)continue;
                    for(int d = 0; d < 2; ++d){
                        if(p && d < a[i])continue;
                        if(q && d > b[i])continue;
                        int np = p && d == a[i];
                        int nq = q && d == b[i];
                        int nj = j + d;
                        int ni = i + 1;
                        dp[ni][nj][np][nq] += dp[i][j][p][q];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            ans += dp[sz][K][i][j];
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> K;
    ll l = 1 , r = 1e18 , ans = -1;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(count(mid) >= M){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}   
