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
bool check(const vector<int>& a , int x){
    vector<int> b;
    for(int i : a)if(i != x)b.push_back(i);
    vector<int> nb = b;
    reverse(nb.begin() , nb.end());
    return b == nb;
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
        int ok = 1;
        for(int i = 0 , j = N - 1; i <= j; ++i , --j){
            if(a[i] != a[j]){
                if(check(a , a[i]) == false && check(a , a[j]) == false){
                    ok = 0;
                }
                break;
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