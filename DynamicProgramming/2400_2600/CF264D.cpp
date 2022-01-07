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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
char a[maxv] , b[maxv];
int N , M , fa[maxv] , fb[maxv] , s[maxv][3][3];
int A[maxv], B[maxv];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> (a + 1);
    cin >> (b + 1);
    N = strlen(a + 1);
    M = strlen(b + 1);
    int i , j;
    for(i = 1; i <= N; ++i){
        if(a[i] == 'R')A[i] = 0;
        if(a[i] == 'B')A[i] = 1;
        if(a[i] == 'G')A[i] = 2;
    }
    for(i = 1; i <= M; ++i){
        if(b[i] == 'R')B[i] = 0;
        if(b[i] == 'B')B[i] = 1;
        if(b[i] == 'G')B[i] = 2;
    }
    s[2][B[1]][B[2]] = 1;
    for(int i = 3; i <= M; ++i){
        ++s[i][B[i - 1]][B[i]];
        for(int x = 0; x < 3; ++x){
            for(int y = 0; y < 3; ++y){
                s[i][x][y] += s[i - 1][x][y];
            }
        }
    }
    for(i = 1 , j = 1; i <= N; ++i){
        // fa[i] = smallest j such that a[1..i] is a subsequence of b[1..j]
        while(j <= M && B[j] != A[i])++j;
        fa[i] = min(j , M);
        if(j <= M && B[j] == A[i])++j;
    }
    for(i = 1 , j = 1; i <= M; ++i){
        // fa[i] = smallest j such that a[1..i] is a subsequence of b[1..j]
        while(j <= N && A[j] != B[i])++j;
        fb[i] = min(j , N);
        if(j <= N && A[j] == B[i])++j;
    }
    ll ans = 0;
    for(i = 1 , j = 1; i <= N; ++i){
        // for each i, calculate number good states in B
        int t = fa[i];
        while(j <= M && fb[j] < i)++j;
        int cj = j;
        if(cj <= t){
            ans += (t - cj + 1);
            if(i > 1 && t - cj + 1 >= 2 && A[i - 1] != A[i]){
                ans -= s[t][A[i]][A[i - 1]] - s[cj - 1][A[i]][A[i - 1]];
            }
        }
    }
    cout << ans << endl;
}