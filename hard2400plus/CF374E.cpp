#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
const int maxn = 1e5 + 10;
const int inf32 = 1e9;
const ll inf64 = 1e18;
bool DFS(int v , int goal , int p , int len , vector<vector<int>>& g){
    if(len == 0){
        return v == goal;
    }
    for(int nv : g[v]){
        if(p == nv)continue;
        if(DFS(nv , goal , v , len - 1 , g))return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , M;
    cin >> N >> M;
    vector<pll> red(M) , blue(N); 
    for(int i = 0; i < N; ++i){
        cin >> blue[i].x >> blue[i].y;
    }
    for(int i = 0; i < M; ++i){
        cin >> red[i].x >> red[i].y;
    }
    auto check = [&](ll t) -> bool {
        // (x , y) -> (x + y , x - y)
        // blue -> vertical
        // red -> horizontal
        vector<array<ll , 4>> vertical(N) , horizontal(M);
        // (x1 , y1) , (x2 , y2)
        for(int i = 0; i < N; ++i){
            ll x1 = blue[i].x - t;
            ll y1 = blue[i].y + t;
            ll x2 = blue[i].x + t;
            ll y2 = blue[i].y - t;
            vertical[i][0] = x1 + y1;
            vertical[i][1] = x1 - y1;
            vertical[i][2] = x2 + y2;
            vertical[i][3] = x2 - y2;
            // x stays same
        }
        for(int i = 0; i < M; ++i){
            ll x1 = red[i].x + t;
            ll y1 = red[i].y + t;
            ll x2 = red[i].x - t;
            ll y2 = red[i].y - t;
            horizontal[i][2] = x1 + y1;
            horizontal[i][3] = x1 - y1;
            horizontal[i][0] = x2 + y2;
            horizontal[i][1] = x2 - y2;
            // y stays same
        }
        vector<int> used_v(N , -1) , used_h(M , -1);
        vector<array<ll , 4>> nv , nh;
        // merge vertical
        for(int i = 0; i < N; ++i){
            if(~used_v[i])continue;
            array<ll , 4> cur = vertical[i];
            used_v[i] = 1;
            for(int j = 0; j < N; ++j){
                if(i == j)continue;
                if(cur[0] != vertical[j][0])continue; // x not the same
                ll l = vertical[j][1] , r = vertical[j][3];
                if(max(l , cur[1]) > min(r , cur[3]))continue;
                used_v[j] = 1;
                cur[1] = min(cur[1] , l);
                cur[3] = max(cur[3] , r);
            }
            nv.push_back(cur);
        }
        // merge horizontal
        for(int i = 0; i < M; ++i){
            if(~used_h[i])continue;
            array<ll , 4> cur = horizontal[i];
            used_h[i] = 1;
            for(int j = 0; j < M; ++j){
                if(i == j)continue;
                if(cur[1] != horizontal[j][1])continue; // y not the same
                ll l = horizontal[j][0] , r = horizontal[j][2];
                if(max(l , cur[0]) > min(r , cur[2]))continue;
                used_h[j] = 1;
                cur[0] = min(cur[0] , l);
                cur[2] = max(cur[2] , r);
            }
            nh.push_back(cur);
        }
        vertical = nv;
        horizontal = nh;
        int NN = vertical.size();
        int MM = horizontal.size();
        vector<vector<int>> g(NN + MM , vector<int>());
        for(int i = 0; i < NN; ++i){
            for(int j = 0; j < MM; ++j){
                ll yh = horizontal[j][1];
                ll xv = vertical[i][0];
                ll xh1 = horizontal[j][0];
                ll xh2 = horizontal[j][2];
                ll yv1 = vertical[i][1];
                ll yv2 = vertical[i][3];
                if(
                    min(yv1 , yv2) <= yh &&
                    yh <= max(yv1 , yv2) &&
                    min(xh1 , xh2) <= xv &&
                    xv <= max(xh1 , xh2)
                ){
                    g[i].push_back(NN + j);
                    g[NN + j].push_back(i);
                }
            }
        }
        for(int v = 0; v < NN; ++v){
            if(DFS(v , v , v , 4 , g))return true;
        }
        return false;
    };
    ll l = 0 , r = inf64 , ans = inf64;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(ans >= inf64){
        cout << "Poor Sereja!" << endl;
    }
    else{
        cout << ans << endl;
    }
}       