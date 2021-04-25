#include <bits/stdc++.h>
using namespace std;
int N , M , Q;
char g[45][45];
int cnt[45][45] , f[45][45][45][45];

// f[x1][y1][x2][y2] = number of full 0 rectangles
// with top left conner = (x1 , y1) , and bottom right 
// conner bounded by (x2 , y2)

int get(int x1 , int y1 , int x2 , int y2){
    // top left , bottom right
    if(x1 > x2 || y1 > y2)return 0;
    return cnt[x2][y2] - cnt[x2][y1 - 1] - cnt[x1 - 1][y2] + cnt[x1 - 1][y1 - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; ++i){
        cin >> (g[i] + 1);
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            if(g[i][j] == '1')++cnt[i][j];
        }
    }
    for(int x1 = 1; x1 <= N; ++x1){
        for(int y1 = 1; y1 <= M; ++y1){
            for(int x2 = x1; x2 <= N; ++x2){
                for(int y2 = y1; y2 <= M; ++y2){
                    f[x1][y1][x2][y2] = get(x1 , y1 , x2 , y2) == 0;
                    f[x1][y1][x2][y2] += f[x1][y1][x2][y2 - 1] + f[x1][y1][x2 - 1][y2];
                    f[x1][y1][x2][y2] -= f[x1][y1][x2 - 1][y2 - 1];
                    // printf("f[%d][%d][%d][%d] = %d\n" , x1 , y1 , x2 , y2 , f[x1][y1][x2][y2]);
                }
            }
        }
    }
    while(Q--){
        int x1 , y1 , x2 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for(int i = x1; i <= x2; ++i){
            for(int j = y1; j <= y2; ++j){
                ans += f[i][j][x2][y2];
            }
        }
        cout << ans << endl;
    }
}