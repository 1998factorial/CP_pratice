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
const int maxn = 1e5 + 10;
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
        ll n , m , k;
        cin >> n >> m >> k;
        if(m > n * (n - 1) / 2 || m < n - 1){
            cout << "NO" << endl;
            continue;
        }
        if(k <= 1){
            cout << "NO" << endl;
        }
        else if(k == 2){
            if(n == 1){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }   
        else if(k == 3){
            if(m == n * (n - 1) / 2){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else{
            cout << "YES" << endl;
        }
    }
} 