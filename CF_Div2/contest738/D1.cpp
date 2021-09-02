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
int N , M[2];
int fa[1005][2];
void init(){
    for(int j = 0; j < 2; ++j){
        for(int i = 1; i <= N; ++i)fa[i][j] = i;
    }
}
int find(int x , int j){
    return fa[x][j] == x ? x : fa[x][j] = find(fa[x][j] , j);
}
bool unite(int x , int y){
    int x0 = find(x , 0);
    int y0 = find(y , 0);
    int x1 = find(x , 1);
    int y1 = find(y , 1);
    if(x0 == y0 || x1 == y1){
        return false;
    }
    fa[x0][0] = y0;
    fa[x1][1] = y1;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M[0] >> M[1];
    init();
    for(int j = 0; j < 2; ++j)
    for(int i = 1; i <= M[j]; ++i){
        int x , y;
        cin >> x >> y;
        x = find(x , j);
        y = find(y , j);
        fa[x][j] = y;
    }
    vector<pii> ans;
    for(int i = 1; i <= N; ++i){
        for(int j = i + 1; j <= N; ++j){
            if(unite(i , j)){
                ans.push_back({i , j});
            }
        }
    }
    cout << ans.size() << endl;
    for(auto& e : ans){
        cout << e.x << " " << e.y << endl;
    } 
}   