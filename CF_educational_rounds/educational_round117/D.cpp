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
ll gcd(ll x , ll y){
    return x == 0 ? y : gcd(y % x , x);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll a , b , x;
        cin >> a >> b >> x;
        /*
        set<pair<ll,ll>> v;
        v.insert({max(a,b) , min(b,a)});
        for(int i = 1; i <= 500; ++i){
            auto nv = v;
            for(auto e : v){
                ll l = e.x , r = abs(e.x - e.y);
                nv.insert({max(l , r) , min(l , r)});
                l = abs(e.x - e.y) , r = e.y;
                nv.insert({max(l , r) , min(l , r)});
            }
            v = nv;
        }
        for(auto e : v){
            cout<<"("<<e.x<< " "<<e.y<<")"<<" ";
        }
        cout << endl;
        */
        /*
        int ok = 0;
        if(a < b)swap(a , b);
        if(a == x || b == x)ok = 1;
        while(a && b){
            if(a < b)swap(a , b);
            if(a == x || b == x)ok = 1;
            ll diff = a - b;
            if(diff == x)ok = 1;
            a = diff;
        }
        if(ok)cout << "YES" << endl;
        else cout << "NO" << endl;
        */
        int ok = 0;
        if(a < b)swap(a , b);
        if(a == x || b == x)ok = 1;
        while(a && b){
            if(a < b)swap(a , b);
            if(a >= x && a % b == x % b){
                ok = 1;
                break;
            }
            a = a % b;
        }
        if(ok)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}