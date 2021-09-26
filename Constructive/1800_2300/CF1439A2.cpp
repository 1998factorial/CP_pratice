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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , M;
        cin >> N >> M;
        vector<vector<int>> a(N , vector<int>(M));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                cin >> a[i][j];
            }
        }
        
        vector<vector<int>> ans;
        cout << (int)ans.size() << endl;
        for(auto v : ans){
            for(int i : v){
                cout << i << " ";
            }
            cout << endl;
        }
    }
} 
