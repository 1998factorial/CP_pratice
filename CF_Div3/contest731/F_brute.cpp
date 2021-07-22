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
const int inf32 = 1e9;
const ll inf64 = 1e18;
int gcd(int x , int y){
    return x == 0 ? y : gcd(y % x , x);
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
        vector<int> a(N);
        for(int i = 0; i < N; ++i)cin >> a[i];
        int gcd_all = a[0];
        for(int i = 0; i < N; ++i)gcd_all = gcd(gcd_all , a[i]);
        int ans = 0;
        for(;;){
            int ok = 1;
            for(int i = 0; i < N - 1; ++i){
                if(a[i] != a[i + 1])ok = 0;
            }
            if(ok)break;
            vector<int> na(N);
            for(int i = 0; i < N; ++i){
                na[i] = gcd(a[i] , a[(i + 1) % N]);
            }
            a = na;
            ++ans;
        }
        cout << "final form \n";
        for(int i : a)cout << i << " " , assert(i == gcd_all);
        cout << endl;
        //cout << ans << endl;
    }
}   