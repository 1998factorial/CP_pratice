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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        //[min is a] [max is b]
        int n , a , b;
        cin >> n >> a >> b;
        vector<int> L , R;
        vector<bool> vis(n + 1);
        int ok = 1;
        for(int i = 1; i < a; ++i)R.push_back(i) , vis[i] = 1;
        for(int j = b + 1; j <= n; ++j){
            if(vis[j]){
                ok = 0;
                break;
            }
            L.push_back(j) , vis[j] = 1;
        }
        if(vis[a] == 0){
            vis[a] = 1;
            L.push_back(a);
        }
        if(vis[b] == 0){
            vis[b] = 1;
            R.push_back(b);
        }
        for(int i = 1; i <= n; ++i){
            if(vis[i])continue;
            if(i < a){
                if(R.size() >= n / 2)ok = 0;
                R.push_back(i);
                continue;
            }
            if(i > b){
                if(L.size() >= n / 2)ok = 0;
                L.push_back(i);
                continue;
            }
            if(L.size() < n / 2){
                L.push_back(i);
                continue;
            }
            if(R.size() < n / 2){
                R.push_back(i);
                continue;
            }
        }

        if(L.size() != n / 2 || R.size() != n / 2)ok = 0;
        if(ok == 0){
            cout << -1 << endl;
            continue;
        }
        for(int i : L)cout << i << " ";
        for(int i : R)cout << i << " ";
        cout<< endl;
    }
}