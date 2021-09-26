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
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N + 1) , b(N + 1);
    vector<int> L , R;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= N; ++i)cin >> b[i];
    ll sum = 0;
    for(int i = 1; i <= N; ++i){
        if(a[i] < b[i]){
            L.push_back(i);
        }
        if(a[i] > b[i]){
            R.push_back(i);
        }
        sum += abs(a[i] - b[i]);
    }
    // [ai , bi]
    sort(L.begin() , L.end() , [&](int& l , int& r){
        return a[l] < a[r];
    });
    // [bi , ai]
    sort(R.begin() , R.end() , [&](int& l , int& r){
        return b[l] < b[r];
    });
    // force b[j] <= a[i]
    ll delta = 0;
    int max_a = 0;
    for(int i = 0 , j = 0; i < L.size(); ++i){
        while(j < R.size() && b[R[j]] <= a[L[i]]){
            max_a = max(max_a , a[R[j]]);
            ++j;
        }
        ll v = (max_a >= b[L[i]]) ? b[L[i]] - a[L[i]] : max_a - a[L[i]];
        delta = max(delta , v);
    }
    // force a[j] <= b[i]
    int max_b = 0;
    for(int i = 0 , j = 0; i < R.size(); ++i){
        while(j < L.size() && a[L[j]] <= b[R[i]]){
            max_b = max(max_b , b[L[j]]);
            ++j;
        }
        ll v = (max_b >= a[R[i]]) ? a[R[i]] - b[R[i]] : max_b - b[R[i]];
        delta = max(delta , v);
    }
    cout << sum - delta * 2 << endl;
} 