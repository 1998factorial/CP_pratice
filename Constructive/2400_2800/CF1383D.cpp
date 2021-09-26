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
int a[255][255] , N , M , ans[255][255] , cnt[255][255];
int dir[4][2] = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
bool inside(int x , int y){
    return 1 <= x && x <= N && 1 <= y && y <= M;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> a[i][j];
        }
    }
    set<int> row_max , col_max;
    for(int i = 1; i <= N; ++i){
        int max_v = 1;
        for(int j = 1; j <= M; ++j){
            max_v = max(max_v , a[i][j]);
        }
        row_max.insert(max_v);
    }
    for(int i = 1; i <= M; ++i){
        int max_v = 1;
        for(int j = 1; j <= N; ++j){
            max_v = max(max_v , a[j][i]);
        }
        col_max.insert(max_v);
    }
    pii cur = make_pair(0 , 0);
    set<pii> remain;
    for(int i = N * M; i >= 1; --i){
        int is_max_row = 0 , is_max_col = 0;
        if(row_max.count(i))is_max_row = 1;
        if(col_max.count(i))is_max_col = 1;
        if(is_max_row)++cur.x;
        if(is_max_col)++cur.y;
        pii pos = make_pair(0 , 0);
        if(is_max_col || is_max_row){
            pos = cur;
            ans[cur.x][cur.y] = i;
        }
        // now we need to put i on some non-dominant position
        // where?
        // places that are both horizontally & vertically adjcent to decided cells
        else{
            if(remain.empty()){
                cout << -1 << endl;
                return 0;
            }
            auto val = *remain.begin();
            remain.erase(remain.begin());
            ans[val.x][val.y] = i;
            pos = val;
        }
        assert(pos.x && pos.y);
        for(int j = 0; j < 4; ++j){
            int nx = pos.x + dir[j][0];
            int ny = pos.y + dir[j][1];
            if(!inside(nx , ny))continue;
            ++cnt[nx][ny];
            if(ans[nx][ny] == 0 && cnt[nx][ny] >= 2){
                remain.insert(make_pair(nx , ny));
            }
        }
    }            
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
} 