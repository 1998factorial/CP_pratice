#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
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
int N , M , x[maxn] , y[maxn];
int big[maxn];
int small[455][455];
int lim;
int start[maxn];
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    scanf("%d %d" , &N , &M);
    //cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        //cin >> x[i] >> y[i];
        scanf("%d %d" , &x[i] , &y[i]);
        x[i] = min(x[i] , M);
        y[i] = min(y[i] , M);
    }
    int ans = 0 , sum = 0;
    lim = sqrt(M);
    for(int t = 0; t < M; ++t){
        int op , k;
        scanf("%d %d" , &op , &k);
        //cin >> op >> k;
        if(op == 1){
            // add
            start[k] = t;
            int step = x[k] + y[k];
            if(step <= lim){
                for(int i = x[k]; i < step; ++i){
                    ++small[step][(i + t) % step];
                }
            }
            else{
                for(int i = t + x[k]; i <= M; i += step){
                    ++big[i];
                    if(i + y[k] <= M)--big[i + y[k]];
                }
            }
        }
        else{
            // del
            int s = start[k];
            int step = x[k] + y[k];
            if(step <= lim){
                for(int i = x[k]; i < step; ++i){
                    --small[step][(i + s) % step];
                }
            }
            else{
                for(int i = s + x[k]; i <= M; i += step){
                    --big[i];
                    if(i + y[k] <= M)++big[i + y[k]];
                    if(i < t && t <= i + y[k]){
                        --sum;
                    }
                }
            }
        }
        sum += big[t];
        ans = sum;
        for(int i = 1; i <= lim; ++i){
            ans += small[i][t % i];
        }
        printf("%d\n" , ans);
        //cout << ans << endl;
    }
} 