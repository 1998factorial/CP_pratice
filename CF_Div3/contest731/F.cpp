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
int table[25][maxn];
int logs[maxn];
int gcd(int x , int y){
    return x == 0 ? y : gcd(y % x , x);
}
int query(int l, int r) {
    if(l > r)return 1;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return gcd(table[logs[len]][l] , table[logs[len]][pos]);
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
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        int g = a[0];
        for(int i : a)g = gcd(i , g);
        for(int i = 2; i < maxn; ++i){
            logs[i] = logs[i / 2] + 1;
        }
        for(int i = 0; i < N; ++i){
            table[0][i] = a[i];
        }
        for(int i = 1; i <= logs[N]; ++i){
            int prel = (1 << (i - 1));
            for(int j = 0; j < N; ++j){
                if(j + prel < N){
                    table[i][j] = gcd(table[i - 1][j] , table[i - 1][j + prel]);
                }
                else{
                    table[i][j] = table[i - 1][j];
                }
            }
        }
        // answer is bounded by N - 1
        int l = 0 , r = N - 1 , ans = N - 1;
        while(l <= r){
            int mid = (l + r) / 2 , ok = 1;
            for(int i = 0; i < N; ++i){
                // [i , i + mid]
                if(i + mid < N){
                    int v = query(i , i + mid);
                    if(v != g)ok = 0;
                }
                else{
                    int v = query(i , N - 1);
                    v = gcd(v , query(0 , (i + mid) % N));
                    if(v != g)ok = 0;
                }
            }
            if(ok){
                ans = mid;
                r = mid - 1;
            }   
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}   
