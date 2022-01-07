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
int dis(int x1 , int y1 , int x2 , int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x , y;
        cin >> x >> y;
        int ax = -1 , ay = -1;
        for(int i = -150; i <= 150; ++i){
            for(int j = -150; j <= 150; ++j){
                if(dis(0 , 0 , i , j) * 2 == dis(0 , 0 , x , y)
                    && dis(x , y , i , j) * 2 == dis(0 , 0 , x , y)
                ){
                    ax = i , ay = j;
                    break;
                }
            }
        }
        cout << ax << " " << ay << endl;
    }
}