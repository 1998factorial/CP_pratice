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
const int inf32 = 1e9 + 10000;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int xa , xb , ya , yb , xf , yf;
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xf >> yf;
        if(xa != xb && ya != yb){
            cout << abs(xa - xb) + abs(ya - yb) << endl;
        }
        else{
            if(xa == xb && xa == xf && min(ya , yb) <= yf && yf <= max(ya , yb)){
                cout << 2 + abs(xa - xb) + abs(ya - yb) << endl;
            }
            else if(ya == yb && ya == yf && min(xa , xb) <= xf && xf <= max(xa , xb)){
                cout << 2 + abs(xa - xb) + abs(ya - yb) << endl;
            }
            else{
                cout << abs(xa - xb) + abs(ya - yb) << endl;
            }
        }
    }
}   
