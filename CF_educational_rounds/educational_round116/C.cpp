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
        ll n , k;
        cin >> n >> k;
        ++k;
        vector<int> a(10);
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            a[x] = 1;
        }
        vector<int> vec;
        for(int i = 0; i < 10; ++i){
            if(a[i] == 0)continue;
            vec.push_back(i);
        }
        vector<ll> ans;
        for(int x = 0 , j = 1; x < vec.size() && k > 0; ++x){
            int i = vec[x];
            if(x < vec.size() - 1){
                int diff = vec[x + 1] - vec[x];
                ll v = 9;
                for(int t = 2; t <= diff; ++t){
                    v = v * 10 + 9;
                }
                v = min(v , k);
                ans.push_back(v);
                k -= v;
            }
            else{
                ans.push_back(k);
                k = 0;
                break;
            }
        }
        reverse(ans.begin() , ans.end());
        for(auto i : ans)cout << i;
        cout << endl;
    }

}