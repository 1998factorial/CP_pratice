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
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int c , d;
        cin >> c >> d;
        if((c & 1) != (d & 1)){
            cout << -1 << endl;
        }
        else{
            if(c == 0 && d == 0){
                cout << 0 << endl;
            }
            else{
                if(c == d){
                    cout << 1 << endl;
                }
                else{
                    cout << 2 << endl;
                }
            }
        }
    }
} 