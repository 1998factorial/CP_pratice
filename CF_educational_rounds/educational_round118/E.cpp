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
int dir[4][2] = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    scanf("%d" , &t);
    while(t--){
        int N , M;        
        cin >> N >> M;
        vector<vector<int>> g(N * M + 10 , vector<int>());
        char a[N + 10][M + 10];
        for(int i = 0; i < N; ++i){
            scanf("%s" , a[i]);
        }
        auto id = [&](int i , int j) -> int {
            return i * M + j;
        };
        auto rid = [&](int id) -> pair<int , int> {
            return {id / M , id % M};
        };
        auto in = [&](int i , int j) -> bool {
            return 0 <= i && i < N && 0 <= j && j < M;
        };
        int s = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(a[i][j] == '.'){
                    int cnt = 0;
                    for(int x = 0; x < 4; ++x){
                        int ni = i + dir[x][0] , nj = j + dir[x][1];
                        if(!in(ni , nj))continue;
                        if(a[ni][nj] == '.' || a[ni][nj] == 'L')++cnt;
                    }
                    if(cnt <= 2){
                        for(int x = 0; x < 4; ++x){
                            int ni = i + dir[x][0] , nj = j + dir[x][1];
                            if(!in(ni , nj))continue;
                            if(a[ni][nj] == '.' || a[ni][nj] == 'L'){
                                g[id(ni , nj)].push_back(id(i , j));
                            }
                        }
                    }
                }
                if(a[i][j] == 'L')s = id(i , j);
            }
        }
        queue<int> q;
        vector<vector<bool>> vis(N , vector<bool>(M));
        q.push(s);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            auto cur = rid(v);
            if(vis[cur.x][cur.y])continue;
            vis[cur.x][cur.y] = true;
            for(int nv : g[v]){
                auto nc = rid(nv);
                if(vis[nc.x][nc.y])continue;
                q.push(nv);
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(vis[i][j]){
                    int ok = 0;
                    for(int x = 0; x < 4; ++x){
                        int ni = i + dir[x][0] , nj = j + dir[x][1];
                        if(!in(ni , nj))continue;
                        if(a[ni][nj] == '.' && !vis[ni][nj])ok = 1;
                    }
                    if(ok)q.push(id(i , j));
                }
            }
        }
        vector<vector<bool>> seen(N , vector<bool> (M));
        while(!q.empty()){
            int v = q.front();
            q.pop();
            auto cur = rid(v);
            if(seen[cur.x][cur.y])continue;
            seen[cur.x][cur.y] = true;
            vis[cur.x][cur.y] = true;
            for(int x = 0; x < 4; ++x){
                int i = cur.x + dir[x][0] , j = cur.y + dir[x][1];
                if(!in(i , j))continue;
                if(seen[i][j])continue;
                if(vis[i][j])continue;
                if(a[i][j] == '#')continue;
                int c = 0;
                for(int y = 0; y < 4; ++y){
                    int ni = i + dir[y][0] , nj = j + dir[y][1];
                    if(!in(ni , nj))continue;
                    if(a[ni][nj] == '.' && vis[ni][nj] == false){
                        ++c;
                    }
                }
                if(c <= 1)q.push(id(i , j));
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(vis[i][j] && a[i][j] == '.')a[i][j] = '+';
            }
            printf("%s\n" , a[i]);
        }
    }
}
