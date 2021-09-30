#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
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
int M , K;
/*
[R][B][R][B][R][B]
[Y][W][Y][W][Y][W]
[R][B][R][B][R][B]
[Y][W][Y][W][Y][W]
[R][B][R][B][R][B]
[Y][W][Y][W][Y][W]
W : empty
things in Y and B are different
R can be anything

feed the most frequent elements into B first
if we run out of B, feed into R
next frequent element, we start with B or Y
*/
vector<vector<int>> construct(int side , vector<pii> ps , int& ok){
    vector<vector<int>> ans(side , vector<int>(side , 0));
    ok = 1;
    vector<pii> red , yellow , blue;
    for(int i = 0; i < side; ++i){
        for(int j = 0; j < side; ++j){
            if((i + j) % 2 == 0){
                if(i % 2 == 0)red.push_back({i , j});
            }
            else{
                if(i % 2 == 0){
                    blue.push_back({i , j});
                }
                else{
                    yellow.push_back({i , j});
                }
            }
        }
    }
    reverse(blue.begin() , blue.end());
    reverse(red.begin() , red.end());
    reverse(yellow.begin() , yellow.end());
    for(int i = 0; i < ps.size(); ++i){
        if(!blue.empty()){
            while(ps[i].x > 0 && !blue.empty()){
                auto cur = blue.back();
                blue.pop_back();
                --ps[i].x;
                ans[cur.x][cur.y] = ps[i].y + 1;
            }
        }
        else{
            while(ps[i].x > 0 && !yellow.empty()){
                auto cur = yellow.back();
                yellow.pop_back();
                --ps[i].x;
                ans[cur.x][cur.y] = ps[i].y + 1;
            }
        }
        while(ps[i].x > 0 && !red.empty()){
            auto cur = red.back();
            red.pop_back();
            --ps[i].x;
            ans[cur.x][cur.y] = ps[i].y + 1;
        }
        if(ps[i].x > 0){
            ok = 0;
            break;
        }
    }
    /*for(int i = 0; i < side; ++i){
        for(int j = 0; j < side; ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }*/
    return ans;
}
void solve(){
    cin >> M >> K;
    vector<int> cnt(K);
    for(int i = 0; i < K; ++i)cin >> cnt[i];
    vector<pii> ps;
    for(int i = 0; i < K; ++i)ps.push_back({cnt[i] , i});
    sort(ps.rbegin() , ps.rend());
    int l = 0 , r = 4 * sqrt(M) , ans = r , ok = 1;
    while(l <= r){
        int mid = (l + r) / 2;
        construct(mid , ps , ok);
        if(ok){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    auto mat = construct(ans , ps , ok);
    cout << ans << endl;
    for(int i = 0; i < mat.size(); ++i){
        for(int j = 0; j < mat[0].size(); ++j){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
} 