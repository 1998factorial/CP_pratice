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
const int mod = 1e9 + 7;
ll gcd(ll x , ll y){
    return x == 0 ? y : gcd(y % x , x);
}
ll table[25][maxn];
ll logs[maxn];
ll query(int l, int r) {
    if(l > r)return 1;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return gcd(table[logs[len]][l] , table[logs[len]][pos]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 2; i < maxn; ++i){
        logs[i] = logs[i / 2] + 1;
    }
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<ll> a(N) , diff;
        for(int i = 0; i < N; ++i)cin >> a[i];
        for(int i = 0; i + 1 < N; ++i)diff.push_back(abs(a[i + 1] - a[i]));
        for(int i = 0; i < N - 1; ++i){
            table[0][i] = diff[i];
        }
        for(int i = 1; i <= logs[N - 1]; ++i){
            int prel = (1 << (i - 1));
            for(int j = 0; j < N - 1; ++j){
                if(j + prel < N - 1){
                    table[i][j] = gcd(table[i - 1][j] , table[i - 1][j + prel]);
                }
                else{
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        int ans = 1 , l = 1 , r = N - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int ok = 0;
            for(int i = 0; i < N - 1; ++i){
                if(i + mid - 1 < N - 1 && query(i , i + mid - 1) > 1){
                    ok = 1;
                    break;
                }
            }
            if(ok){
                ans = mid + 1;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
} 