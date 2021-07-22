#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i)cin >> a[i];
    if(N <= 2 || N % 2 == 0){
        cout << -1 << endl;
        exit(0);
    }
    int ans = 0;
    for(int i = N; i >= 2; i -= 2){
        int x = i / 2;
        while(a[i] > 0 || a[i - 1] > 0){
            if(a[x] > 0)--a[x];
            if(a[i] > 0)--a[i];
            if(a[i - 1] > 0)--a[i - 1];
            ++ans;
        }
    }
    cout << ans + a[1] << endl;
}   