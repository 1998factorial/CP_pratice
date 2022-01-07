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
const int maxn = 5e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
// divde into 2 parts
// part 1: a <= s, we can select all in part 1, by selecting in s[i] increasing order
// part 2: a > s, we can only select disjoint ones, we can find such set 
// by a[i] increasing order (choose smallest a when making decision)
// we can greedly combine part 1 and part 2
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int N , D;
        cin >> N >> D;
        vector<pii> part1 , part2;
        for(int i = 1; i <= N; ++i){
            int s , a;
            cin >> s >> a;
            if(s < D)continue;
            if(a <= s)part1.push_back({s , a});
            if(a > s)part2.push_back({s , a});
        }
        sort(part1.begin() , part1.end() , [&](pii& l , pii& r){
            return l.x < r.x;
        });
        sort(part2.begin() , part2.end() , [&](pii& l , pii& r){
            return l.y < r.y;
        });
        int ans = 0 , i = 0 , j = 0;
        for(; i < part1.size(); ++i){
            while(j < part2.size() && part2[j].y <= part1[i].x){
                if(part2[j].x >= D){
                    D = max(D , part2[j].y);
                    ++ans;
                }
                ++j;
            }
            D = max(D , part1[i].y);
            ++ans;
        }
        for(; j < part2.size(); ++j){
            if(part2[j].x >= D){
                D = max(D , part2[j].y);
                ++ans;
            }
        }
        cout << ans << endl;
    }
}