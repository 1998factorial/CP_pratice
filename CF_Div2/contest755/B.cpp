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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int solve(int n , int m){
        int ans = 1e9;
        if(n % 3 == 0){
            if(m % 3 == 0){
                ans =  min(ans , m * (n / 3));
            }
            if(m % 3 == 1){
                ans =  min(ans , m * (n / 3));
            }
            if(m % 3 == 2){
                ans =  min(ans , m * (n / 3));
            }
        }
        if(n % 3 == 1){
            if(m % 3 == 0){
                ans = min(ans , (n / 3) * m + m / 3);
            }
            if(m % 3 == 1){
                ans = min(ans , (n / 3) * m + (m + 2) / 3);
            }
            if(m % 3 == 2){
                ans = min(ans , (n / 3) * m + (m + 2) / 3);
            }
        }
        if(n % 3 == 2){
            if(m % 3 == 0){
                ans = min(ans , (n / 3) * m + (m / 3) * 2);
            }
            if(m % 3 == 1){
                ans = min(ans , (n / 3) * m + ((m + 2) / 3) * 2);
            }
            if(m % 3 == 2){
                ans = min(ans , (n / 3) * m + ((m + 2) / 3) * 2);
            }
        }
        return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;
        if(n == 1){
            cout << (m+2)/3 <<endl;
            continue;
        }
        if(m == 1){
            cout << (n+2)/3 <<endl;
            continue;
        }
        int ans=1e9;
        ans = min(solve(n , m) , ans);
        ans = min(solve(m , n) , ans);
        
        cout<<ans<<endl;
    }
}