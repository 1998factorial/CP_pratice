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
const int maxn = 1005;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , M , a[maxn];
double f[maxn][maxn] , f1[maxn] , f2[maxn] , f3[maxn] , f4[maxn];  
// f[i][j] = probability that a[i] > a[j]
// E[inversion] = sum{f[i][j] * [i < j]}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(a[i] > a[j]){
                f[i][j] = 1.0;
            }
        }
    }
    for(int i = 1; i <= M; ++i){
        int l , r;
        cin >> l >> r;
        for(int j = 1; j <= N; ++j){
            f1[j] = f[l][j];
            f2[j] = f[r][j];
            f3[j] = f[j][l];
            f4[j] = f[j][r];
        }
        for(int j = 1; j <= N; ++j){
            if(j == l || j == r)continue;
            f[r][j] = f[l][j] = (f1[j] + f2[j]) / 2;
            f[j][r] = f[j][l] = (f3[j] + f4[j]) / 2;
        }
        f[r][l] = f[l][r] = 0.5;
    }
    double ans = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = i + 1; j <= N; ++j){
            ans += f[i][j];
        }
    }
    cout << setprecision(20) << ans << endl;
}   
