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
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , M , Q , a[1005][1005] , dp[1005][1005][2];
// [0] - 
// [1] |
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> Q;
    ll ans = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            for(int k = 0; k < 2; ++k){
                dp[i][j][k] = 1;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            dp[i][j][0] += dp[i][j - 1][1];
            dp[i][j][1] += dp[i - 1][j][0];
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            for(int k = 0; k < 2; ++k){
                ans += dp[i][j][k];
            }
        }
    }
    ans -= N * M;
    while(Q--){
        int x , y;
        cin >> x >> y;
        ll v = 0 , p = 0 , q = 0;
        // left , up , left , up...
        // down , right , down , right...
        int cx = x , cy = y , c = 1;
        while(1){
            if(cx < 1 || cx > N || cy < 1 || cy > M)break;
            if(a[cx][cy] == 1){
                if(!(cx == x && cy == y))break;
            }
            ++p;
            if(c)--cy;
            else --cx;
            c ^= 1;
        }
        cx = x , cy = y , c = 1;
        while(1){
            if(cx < 1 || cx > N || cy < 1 || cy > M)break;
            if(a[cx][cy] == 1){
                if(!(cx == x && cy == y))break;
            }
            ++q;
            if(c)++cx;
            else ++cy;
            c ^= 1;
        }
        v += p * q;
        p = 0 , q = 0;
        // up , left , up , left...
        // right , down , right , down...
        cx = x , cy = y , c = 1;
        while(1){
            if(cx < 1 || cx > N || cy < 1 || cy > M)break;
            if(a[cx][cy] == 1){
                if(!(cx == x && cy == y))break;
            }
            ++p;
            if(c)--cx;
            else --cy;
            c ^= 1;
        }
        cx = x , cy = y , c = 1;
        while(1){
            if(cx < 1 || cx > N || cy < 1 || cy > M)break;
            if(a[cx][cy] == 1){
                if(!(cx == x && cy == y))break;
            }
            ++q;
            if(c)++cy;
            else ++cx;
            c ^= 1;
        }
        v += p * q;
        --v;
        if(a[x][y] == 0){
            // delete
            ans -= v;
        }
        else{
            // add
            ans += v;
        }
        a[x][y] = a[x][y] ^ 1;
        cout << ans << endl;
    }
} 