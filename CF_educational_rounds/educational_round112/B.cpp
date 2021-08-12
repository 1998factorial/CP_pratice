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
const int maxn = 1e6 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
const double dinf = 10000000000.0;
double dis(double x1 , double y1 , double x2 , double y2){
    return min(abs(x1 - x2) , abs(y1 - y2));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        double W , H , x1 , y1 , x2 , y2 , w , h;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        double dw = x2 - x1 , dh = y2 - y1;
        double ans = dinf;
        // move towards 4 conners
        // (w , h)
        if(w <= x1 || h <= y1){
            ans = 0;
        }
        if(w + dw <= W){
            ans = min(ans , abs(w - x1));
        }
        if(h + dh <= H){
            ans = min(ans , abs(h - y1));
        }
        // (w , H - h)
        if(x1 >= w || y2 <= H - h){
            ans = 0;
        }
        if(w + dw <= W){
            ans = min(ans , abs(x1 - w));
        }
        if(H - h - dh >= 0){
            ans = min(ans , abs(y2 - (H - h - dh)));
        }
        // (W - w , H - h)
        if(x2 <= W - w || y2 <= H - h){
            ans = 0;
        }
        if(W - w - dw >= 0){
            ans = min(ans , abs(x2 - (W - w)));
        }
        if(H - h - dh >= 0){
            ans = min(ans , abs(y2 - (H - h)));
        }
        // (W - w , h)
        if(x2 <= W - w || y1 >= h){
            ans = 0;
        }
        if(W - w - dw >= 0){
            ans = min(ans , abs(x2 - (W - w)));
        }
        if(h + dh <= H){
            ans = min(ans , abs(y1 - (h)));
        }
        if(ans >= dinf){
            ans = -1.0;
        }
        cout << setprecision(10) << ans << endl;
    }
}   
