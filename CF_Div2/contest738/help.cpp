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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    cin >> a;
    int N = a.size();
    int v = 0;
    for(int i = 0; i + 1 < N; ++i){
        if(a[i] == a[i + 1])++v;
    }
    cout <<v << endl;
}  
