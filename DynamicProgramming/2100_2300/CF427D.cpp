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
const int maxn = 5000 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
char a[maxn] , b[maxn];
int N , M;
int lcpa[maxn][maxn] , lcpb[maxn][maxn] , upa[maxn] , upb[maxn] , lcs[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> (a + 1);
    cin >> (b + 1);
    N = strlen(a + 1);
    M = strlen(b + 1);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            if(a[i] == a[j]){
                lcpa[i][j] = lcpa[i - 1][j - 1] + 1;
            }
        }
    }
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= M; ++j){
            if(i == j)continue;
            if(b[i] == b[j]){
                lcpb[i][j] = lcpb[i - 1][j - 1] + 1;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            if(i != j){
                upa[i] = max(upa[i] , lcpa[i][j]);
            }
        }
    }
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= M; ++j){
            if(i != j){
                upb[i] = max(upb[i] , lcpb[i][j]);
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(a[i] == b[j]){
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(lcs[i][j] > upa[i] && lcs[i][j] > upb[j]){
                if(ans == -1 || ans > max(upa[i] , upb[j]) + 1){
                    ans = max(upa[i] , upb[j]) + 1;
                }
            }
        }
    }
    cout << ans << endl;
}   
