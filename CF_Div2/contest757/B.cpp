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
const int maxv = 2e6 + 10;
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
        int N;
        cin >> N;
        vector<int> cnt(N + 1) , id;
        for(int i = 1; i <= N; ++i)cin >> cnt[i] , id.push_back(i);
        sort(id.begin() , id.end() , [&](int& l , int& r){
            return cnt[l] > cnt[r];
        });
        vector<int> ans(N + 1);
        ans[0] = 0;
        int l = -1 , r = 1;
        ll v = 0;
        for(int i : id){
            if(abs(l) < abs(r)){
                v += (ll)cnt[i] * abs(l);
                ans[i] = l;
                --l;
            }
            else{
                v += (ll)cnt[i] * abs(r);
                ans[i] = r;
                ++r;
            }
        }
        cout << v * 2 << endl;
        for(int i : ans)cout << i << ' ';
        cout << endl;
    }
}