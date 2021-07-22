#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
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
        int issorted = 1;
        for(int i = 1; i < N; ++i){
            if(a[i] > a[i + 1])issorted = 0;
        }
        if(issorted){
            cout << 0 << endl;
            continue;
        }
        if(a[1] == 1 || a[N] == N){
            cout << 1 << endl;
            continue;
        }
        if(a[1] == N && a[N] == 1){
            cout << 3 << endl;
            continue;
        }
        cout << 2 << endl;
    }
}