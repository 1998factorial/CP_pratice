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
const int maxn = 4e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int N , M , a[505][505] , b[505][505];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            char s;
            cin >> s;
            if(s == 'B')a[i][j] = 1;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(a[i][j]){
                b[i][j] ^= 1;
                b[i - 1][j] ^= 1;
                b[i][j - 1] ^= 1;
                b[i - 1][j - 1] ^= 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            ans += b[i][j];
        }
    }
    /*for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cout << b[i][j];
        }
        cout << endl;
    }*/
    if(b[N][M]){
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                set<pii> v;
                v.insert({i , j});
                v.insert({i , M});
                v.insert({N , j});
                v.insert({N , M});
                if(b[i][j] && b[i][M] && b[N][j] && v.size() >= 4){
                    ans -= 1;
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
} 