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
        int N; 
        cin >> N;
        vector<int> a(N);
        int up = 1;
        for(int i = 0; i < N; ++i){
            up *= 3;
            cin >> a[i];
        }
        int ok = 0;
        for(int mask = 1; mask < up; ++mask){
            int cur = mask , v = 0;
            for(int i = 0; i < N; ++i){
                int s = cur % 3 , sign = 0;
                if(s == 1)sign = 1;
                if(s == 2)sign = -1;
                v += a[i] * sign;
                cur /= 3;
            }
            if(v == 0){
                ok = 1;
            }
        }
        if(ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
} 
