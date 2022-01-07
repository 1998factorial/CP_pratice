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
const ll mod = 1e9 + 7;
ll gcd(ll x , ll y){
    return x == 0 ? y : gcd(y % x , x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while(t--){
        int N;
        cin >> N;
        vector<ll> a(N);
        for(int i = 0; i < N; ++i){
            cin >> a[i];
        }
        int ans = 0;
        for(int mask = 1; mask < 1 << N; ++mask){
            vector<ll> b;
            for(int i = 0; i < N; ++i){
                if(mask >> i & 1){
                    b.push_back(a[i]);
                }
            }
            ll d = b[0] , val = 0;
            for(ll i : b){
                d = gcd(d , i);
                val += i * (i - 1) / 2;
            }
            if(val % (d) == 0){
                ++ans;
                int check = 0;
                for(auto i : b)if(i % 2 == 1)check = 1;
                if(check == 0){
                    //cout << "werid case \n";
                    //for(auto i : b)cout << i << " ";
                    //cout << endl;
                }
                for(ll i : b)cout << i << " ";
                    cout << endl;
            }
            else{
                //cout << "fail : ";
                //for(ll i : b)cout << i << " ";
                //    cout << endl;
            }
        }
        
        cout << ans << endl;
    }
}