#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;

// sum{p[i] * (n[i] - x[i])} = prod{p[i] * x[i]}
// total - sum{p[i] * x[i]} = prod{p[i] * x[i]}
// RHS grows expoentially which means sum{p[i] * x[i]} will not be too large
// so we can enumerate the value of sum{p[i] * x[i]}

ll solve(){
    int M;
    cin >> M;
    map<ll , ll> cnt;
    ll total = 0;
    for(int i = 1; i <= M; ++i){
        ll p , n;
        cin >> p >> n;
        cnt[p] = n;
        total += p * n;
    }
    for(ll lsum = 2; lsum <= 10000; ++lsum){
        // check if total - lsum can be expressed as product of the 
        // given primes
        ll v = total - lsum;
        ll s = 0;
        for(auto e : cnt){
            if(v <= 1)break;
            ll p = e.x , freq = e.y;
            while(v % p == 0 && freq > 0){    
                v /= p;
                --freq;
                s += p;
            }
        }
        if(lsum == s && v <= 1){
            return total - lsum;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int kase = 1; kase <= t; ++kase){
        cout << "Case #" << kase << ": " << solve() << endl;
    }
}