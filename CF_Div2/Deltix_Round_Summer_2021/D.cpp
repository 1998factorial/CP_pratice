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
const int mod = 1e9 + 7;
int ask(int i , int j , int k){
    if(k == 0){
        cout << "or " << i << " " << j << endl;
        cout.flush();
    }
    else{
        cout << "and " << i << " " << j << endl;
        cout.flush();
    }
    int ans;
    cin >> ans;
    return ans;
}
void answer(int x){
    cout << "finish " << x << endl;
    cout.flush();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 1; i <= 100; ++i){
        for(int j = 1; j <= 100; ++j){
            int v = (i | j);
            v += i & j;
            assert(i + j == v);
        }
    }
    int N , K;
    cin >> N >> K;
    vector<int> val(N + 1) , a(N + 1);
    for(int i = 2; i <= N; ++i){
        val[i] = ask(1 , i , 0) + ask(1 , i , 1);
    }
    int v = ask(2 , 3 , 0) + ask(2 , 3 , 1);
    a[1] = (val[2] + val[3] - v) / 2;
    for(int i = 2; i <= N; ++i){
        a[i] = val[i] - a[1];
    }
    sort(a.begin() + 1 , a.end());
    answer(a[K]);
} 
// 1,6,4,2,3,5,4