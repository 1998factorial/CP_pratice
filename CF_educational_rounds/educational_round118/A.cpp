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
const int maxv = 2e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const ll inf64 = 1e18 + 10;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x1 , p1 , x2 , p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        int t = x1;
        while(t)++p1 , t/=10;
        t = x2;
        while(t)++p2 , t/=10;
        //DEBUG(p1);
        //DEBUG(p2);
        if(p1 > p2){
            cout << ">" << endl;
        }
        else if(p1 < p2){
            cout << "<" << endl;
        }
        else{
            string a = to_string(x1);
            string b = to_string(x2);
            while(a.size() < b.size()){
                a += '0';
            }
            while(a.size() > b.size()){
                b += '0';
            }
            if(a < b){
                cout << "<" << endl;
            }
            if(a > b){
                cout << ">" << endl;
            }
            if(a == b){
                cout << "=" << endl;
            }
        }
    }
}