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

mt19937 rng(std::random_device{}());

ll solve(const vector<ll>& a , ll p){
    ll ans = 0;
    for(auto i : a){
        ll v = p - i % p;
        if(i - i % p > 0)v = min(v , i % p);
        ans += v;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i)cin >> a[i];
    ll ans = solve(a , 2ll);
    for(int ntry = 1; ntry <= 30; ++ntry){
        shuffle(a.begin() , a.end() , rng);
        //int index = rng() % N;
        int index = 0;
        for(int d = -1; d <= 1; ++d){
            ll v = a[index] + d;
            if(v <= 0)continue;
            // factorise
            a[index] += d;
            ll val = v;
            vector<ll> pf;
            for(ll p = 2; p * p <= val; ++p){
                if(val % p == 0){
                    pf.push_back(p);
                    while(val % p == 0){
                        val /= p;
                    }
                }
            }
            if(val > 1)pf.push_back(val);
            for(auto p : pf){
                ans = min(ans , solve(a , p) + (d != 0));
            }
            a[index] -= d;
        }
    }
    cout << ans << endl;
}