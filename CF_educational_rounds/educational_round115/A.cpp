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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<string> a(2);
        cin >> a[0];
        cin >> a[1];
        int ok = 1;
        for(int i = 0; i < N; ++i){
            if(a[0][i] == '1' && a[1][i] == '1')ok = 0;
        }
        if(ok == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
} 