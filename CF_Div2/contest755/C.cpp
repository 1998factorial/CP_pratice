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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n) , b(n);
        for(int i = 0; i < n; ++i)cin >> a[i];
        for(int i = 0; i < n; ++i)cin >> b[i];
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        int i = 0;
        for(int j = 0; j < n; ++j){
            if(a[i] == b[j])++i;
            else if(a[i] == b[j] - 1)++i;
        }
        if(i >= n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}