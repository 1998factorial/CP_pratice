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
int gcd(int a , int b){
    return a == 0 ? b : gcd(b % a , a);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int c = 1 , a , b;
        if((N - 1) & 1){
            a = (N - 1) / 2 , b = N - 1 - a;
        }
        else{
            // (x , N - 1 - x)
            for(int x = 3; x <= N - 1 - x; x += 2){
                if(gcd(x , N - 1 - x) == 1){
                    a = x , b = N - 1 - x;
                    break;
                }
            }
        }
        cout << a << " " << b << " " << c << endl;
    }
}