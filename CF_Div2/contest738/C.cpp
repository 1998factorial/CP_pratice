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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for(int i = 1; i <= N; ++i)cin >> a[i];
        if(a[N] == 0){
            for(int j = 1; j <= N + 1; ++j){
                cout << j << " ";
            }
            cout << endl;
            continue;
        }
        if(a[1] == 1){
            cout << N + 1 << " ";
            for(int j = 1; j <= N; ++j)cout << j << " ";
            cout << endl;
            continue;
        }
        int b = -1;
        for(int j = 1; j + 1 <= N; ++j){
            if(a[j] == 0 && a[j + 1] == 1){
                b = j;
                break;
            }
        }
        if(~b){
            for(int j = 1; j <= b; ++j){
                cout << j << " ";
            }
            cout << N + 1 << " ";
            for(int j = b + 1; j <= N; ++j){
                cout << j << " ";
            }
            cout << endl;
            continue;
        }
        cout << -1 << endl;
    }
}   