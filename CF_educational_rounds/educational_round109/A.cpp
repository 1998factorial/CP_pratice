#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;

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
        int k;
        cin >> k;
        int d = gcd(k , 100);
        cout << 100 / d << endl;
    }
}