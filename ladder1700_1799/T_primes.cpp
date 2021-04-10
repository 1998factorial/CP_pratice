#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;

int check(ll x){
    if(x == 1)return 0;
    // check if x = p * p where p is prime
    ll l = 1 , r = 1e9 , g = -1;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(mid * mid <= x){
            g = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }   
    if(g == -1)return 0;
    if(g * g == x){
        for(ll i = 2; i * i <= g; ++i){
            if(g % i == 0){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> N;
    for(int i = 1; i <= N; ++i){
        ll x;
        cin >> x;
        if(check(x)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
