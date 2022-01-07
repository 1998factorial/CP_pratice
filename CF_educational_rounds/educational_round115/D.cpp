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
const int maxn = 1e5 + 10;
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
        vector<pii> v(N);
        vector<int> cnt(N + 10);
        for(int i = 0; i < N; ++i){
            cin >> v[i].x >> v[i].y;
            ++cnt[v[i].y];
        }
        ll ans = (ll)N * (N - 1) * (N - 2) / 6;
        vector<int> mp[N + 10];
        for(int i = 0; i < N; ++i){
            mp[v[i].x].push_back(v[i].y);
        }
        for(int i = 1; i <= N; ++i){
            if(mp[i].size() < 2)continue;
            ll sum = 0 , acc = 0 , num = 0;
            for(int j : mp[i]){
                sum += acc;
                sum += (cnt[j] - 1) * num;
                acc += cnt[j] - 1;
                ++num;
            }
            ans -= sum;
            /*for(int x = 0; x < mp[i].size(); ++x){
                for(int y = 0; y < x; ++y){
                    ans -= cnt[mp[i][x]] - 1;
                    ans -= cnt[mp[i][y]] - 1;
                }
            }*/
        }
        cout << ans << endl;
    }
} 