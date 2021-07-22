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
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10000;
const ll inf64 = 1e18;
int table[25][maxn];
int logs[maxn];
int gcd(int x , int y){
    return x == 0 ? y : gcd(y % x , x);
}
int query(int l, int r) {
    if(l > r)return 1;
    int len = r - l + 1;
    int pos = r - (1 << logs[len]) + 1;
    return gcd(table[logs[len]][l] , table[logs[len]][pos]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , K;
        cin >> N >> K;
        vector<ll> a(K) , t(K);
        for(int i = 0; i < K; ++i)cin >> a[i];
        for(int i = 0; i < K; ++i)cin >> t[i];
        vector<pll> vec;
        for(int i = 0; i < K; ++i)vec.push_back(make_pair(a[i] , t[i]));
        sort(vec.begin() , vec.end());
        vector<ll> ans(N + 1);
        multiset<ll> L , R;
        for(int i = 0; i < K; ++i){
            R.insert(vec[i].x + vec[i].y);
        }
        int j = 0;
        for(int i = 1; i <= N; ++i){
            while(j < K && vec[j].x <= i){
                if(R.find(vec[j].x + vec[j].y) != R.end())R.erase(R.find(vec[j].x + vec[j].y));
                L.insert(vec[j].y - vec[j].x);
                ++j;
            }
            ll lv = inf64 , rv = inf64;
            if(!L.empty()){
                lv = min(lv , *L.begin());
            }
            if(!R.empty()){
                rv = min(rv , *R.begin());
            }
            ans[i] = min(lv + i , rv - i);
        }
        for(int i = 1; i <= N; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}   
