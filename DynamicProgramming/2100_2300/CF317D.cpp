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
const int maxn = 3e5 + 10;
const int maxq = 5e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int N , SG[30];
map<int , int> f;
int solve(int mask){
    if(f.find(mask) != f.end())return f[mask];
    set<int> mexs;
    for(int i = 0; i < 30; ++i){
        if(mask >> i & 1){
            int nmask = mask;
            for(int j = i; j < 30; j += i + 1){
                if(mask >> j & 1){
                    nmask ^= (1 << j);
                }
            }
            mexs.insert(solve(nmask));
        }
    }
    int ans = 0;
    for(;;++ans){
        if(mexs.find(ans) == mexs.end()){
            break;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    // precalculate SG(1) - SG(29)
    f[0] = SG[0] = 0;
    // for(int i = 14; i <= 14; ++i){
    //     SG[i] = solve((1 << i) - 1);
    //     printf("SG[%d] = %d\n" , i , SG[i]);
    // }
    SG[1] = 1;
    SG[2] = 2;
    SG[3] = 1;
    SG[4] = 4;
    SG[5] = 3;
    SG[6] = 2;
    SG[7] = 1;
    SG[8] = 5;
    SG[9] = 6;
    SG[10] = 2;
    SG[11] = 1;
    SG[12] = 8;
    SG[13] = 7;
    SG[14] = 5;
    SG[15] = 9;
    SG[16] = 8;
    SG[17] = 7;
    SG[18] = 3;
    SG[19] = 4;
    SG[20] = 7;
    SG[21] = 4;
    SG[22] = 2;
    SG[23] = 1;
    SG[24] = 10;
    SG[25] = 9;
    SG[26] = 3;
    SG[27] = 6;
    SG[28] = 11;
    SG[29] = 12;
    set<ll> v;
    v.insert(1);
    ll up = 1;
    for(; (up + 1) * (up + 1) <= N; ++up);
    int n_size_one = N - up + 1 , ans = 0;
    for(ll i = 2; i * i <= N; ++i){
        if(v.find(i) != v.end())continue;
        ll t = i;
        int sz = 0;
        while(t <= N){
            v.insert(t);
            if(t > up)--n_size_one;
            t *= i;
            ++sz;
        }
        ans ^= SG[sz];
    }
    if(n_size_one & 1)ans ^= 1;
    if(ans){
        cout << "Vasya" << endl;
    }
    else{
        cout << "Petya" << endl;
    }
    // cout << "n_size_one = " << n_size_one << endl;
}   
// let pow(x) = {x , x^2 , x^3 ...} intersect [1 , N]
// we can divide [1 , N] into k pow(xi) and pow(xi) intersect pow(xj) = empty set
// now, each time we choose x, x only belongs to exactly one pow(xi)
// so the game can be decomposed into k independent sub games