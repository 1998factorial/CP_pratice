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
        ll ans = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){
                    set<int> x , y;
                    x.insert(v[i].x);x.insert(v[j].x);x.insert(v[k].x);
                    y.insert(v[i].y);y.insert(v[j].y);y.insert(v[k].y);
                    if(x.size() >= 3 || y.size() >= 3){
                        ++ans;
                        //cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
                    }
                    else{
                        vector<pii> vec;
                        vec.push_back(v[i]);
                        vec.push_back(v[j]);
                        vec.push_back(v[k]);
                        sort(vec.begin() , vec.end());
                        for(auto & e : vec){
                            printf("(%d %d) " , e.x , e.y);
                        }
                        cout << endl;
                    }
                }
            }
        }
        cout << ans << endl;
    }
} 