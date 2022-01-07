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
const ll mod = 998244353;
int a[maxn] , N;
int f(int i , int j){
    int ans = 0 , b = a[j];
    for(int k = j - 1; k >= i; --k){
        if(a[k] <= b){
            b = a[k];
            continue;
        }
        int n = ceil((double)a[k] / b);//a[k] / b + (a[k] % b != 0);
        b = a[k] / n;
        ans += n - 1;
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
        cin >> N;
        int ans = 0;
        for(int i = 1; i <= N; ++i)cin >> a[i];
        for(int i = 1; i <= N; ++i){
            int v = 0;
            for(int j = 1; j <= i; ++j){
                ans += f(j , i);
                v += f(j , i);
                //printf("f(%d %d) = %d\n" , i , j , f(i , j));
            }
            printf("end[%d] = %d\n" , i , v);
        }
        cout << ans << endl;
    }
} 