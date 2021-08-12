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
        vector<vector<int>> a(2 * N + 1 , vector<int>(N + 1));
        for(int i = 1; i <= 2 * N; ++i){
            for(int j = 1; j <= N; ++j){
                cin >> a[i][j];
            }
        }
        vector<int> latin_square;
        vector<bool> canuse(2 * N + 1 , true);
        ll ans = 1;
        while(latin_square.size() < N){
            int unique_row = -1;
            for(int i = 1; i <= N && unique_row == -1; ++i){
                vector<int> cnt(N + 1 , 0) , candidate(N + 1 , -1);
                // check if for ith column, if some number appears exactly once
                for(int j = 1; j <= 2 * N; ++j){
                    if(!canuse[j])continue;
                    ++cnt[a[j][i]];
                    candidate[a[j][i]] = j;
                }
                for(int j = 1; j <= N; ++j){
                    if(cnt[j] == 1){
                        unique_row = candidate[j];
                        break;
                    }
                }
            }
            if(unique_row != -1){
                latin_square.push_back(unique_row);
                for(int j = 1; j <= 2 * N; ++j){
                    if(!canuse[j])continue;
                    for(int i = 1; i <= N; ++i){
                        if(a[j][i] == a[unique_row][i])canuse[j] = false;
                    }
                }
            }
            else{
                // now for each column , each integer appears exactly twice
                // and we can choose any one
                ans = mul(ans , 2ll);
                int choose = -1;
                for(int j = 1; j <= 2 * N; ++j){
                    if(canuse[j]){
                        choose = j;
                        break;
                    }
                }
                latin_square.push_back(choose);
                for(int j = 1; j <= 2 * N; ++j){
                    if(canuse[j]){
                        for(int i = 1; i <= N; ++i){
                            if(a[choose][i] == a[j][i]){
                                canuse[j] = false;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        for(int i : latin_square)cout << i << " ";
        cout << endl;
    }
}   
/*
    A very hard problem https://codeforces.com/contest/1546/problem/E
*/
