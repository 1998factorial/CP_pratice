#include <bits/stdc++.h>
using namespace std;
typedef __int128 bigint;

bigint gcd(bigint a , bigint b){
    return a == 0 ? b : gcd(b % a , a);
}

string toString(bigint a){
    string ans = "";
    if(a == 0)return "0";
    while(a > 0){
        ans += '0' + a % 10;
        a /= 10;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

bigint dp[125][125][125] , C[125][125];

void solve(){
    int N , len;
    cin >> N >> len;
    vector<string> a(N);
    vector<int> nc(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i] >> nc[i];
    }
    while(N < 3){
        a.push_back(a.back());
        nc.push_back(nc.back());
        ++N;
    }
    vector<vector<int>> f(N , vector<int>(len , 0));
    vector<int> flip;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < len; ++j){
            if(a[i][j] == 'T')f[i][j] = 1;
        }
    }
    flip = f[0];
    for(int i = 0; i < 3; ++i){
        if(nc[i] == 0){
            for(int j = 0; j < len; ++j){
                if(f[i][j])cout << "F";
                else cout << "T";
            }
            cout << " " << len << "/1" << endl;
            return ;
        }
    }
    // say the first person always say False
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < len; ++j){
            if(flip[j]){
                f[i][j] = 1 - f[i][j];
            }
        }
    }
    vector<vector<int>> cnt(2 , vector<int>(2));
    for(int j = 0; j < len; ++j){
        cnt[f[1][j]][f[2][j]]++;
    }
    vector<bool> answer(len);
    auto get_ways = [&]() -> bigint {
        bigint ret = 0;
        for(int x = 0; x <= cnt[0][0]; ++x){
            // say in the optimal solution there is x T's in (F,F)
            for(int y = 0; y <= cnt[0][1]; ++y){
                // in optimal solution there is y T's in (F,T)
                int c0 = cnt[0][0] - x + cnt[0][1] - y;
                int c1 = cnt[0][0] - x + cnt[0][1] - y;
                int c2 = cnt[0][0] - x + y;
                dp[c0][c1][c2] += C[cnt[0][0]][x] * C[cnt[0][1]][y];
            }
        }
        for(int x = 0; x <= cnt[1][1]; ++x){
            // say in the optimal solution there is x T's in (T,T)
            for(int y = 0; y <= cnt[1][0]; ++y){
                // in optimal solution there is y T's in (T,F)
                int c0 = cnt[1][1] - x + cnt[1][0] - y;
                int c1 = x + y;
                int c2 = x + cnt[1][0] - y;
                if(c0 <= nc[0] && c1 <= nc[1] && c2 <= nc[2]){
                    ret += dp[nc[0] - c0][nc[1] - c1][nc[2] - c2] * C[cnt[1][1]][x] * C[cnt[1][0]][y];
                } 
            }
        }
        for(int x = 0; x <= cnt[0][0] + cnt[0][1]; ++x){
            for(int y = 0; y <= cnt[0][0] + cnt[0][1]; ++y){
                dp[x][x][y] = 0;
            }
        }
        return ret;
    };
    bigint down = get_ways() , up = 0;
    for(int x = 0; x < 2; ++x){
        for(int y = 0; y < 2; ++y){
            if(cnt[x][y] == 0)continue;
            --cnt[x][y];
            if(x > 0)--nc[1]; // person 2 is correct here
            if(y > 0)--nc[2]; // person 3 is correct here
            // get the number of ways that (x,y) evaluates to T is correct
            bigint ways_true = get_ways();
            bigint ways_false = down - ways_true;
            //cout << "at state = " << x << "  " << y << endl;
            //cout << " ways true = " << toString(ways_true) << endl;
            //cout << " ways false = " << toString(ways_false) << endl;
            for(int i = 0; i < len; ++i){
                if(f[1][i] == x && f[2][i] == y){
                    answer[i] = (ways_true >= ways_false);
                    up += max(ways_true , ways_false);
                }
            }
            ++cnt[x][y];
            if(x > 0)++nc[1];
            if(y > 0)++nc[2];
        }
    }
    for(int j = 0; j < len; ++j){
        if(flip[j]){
            answer[j] = 1 - answer[j];
        }
        if(answer[j])cout << "T";
        else cout << "F";
    }
    //cout << "up = " << toString(up) << " down = " << toString(down) << endl; 
    bigint d = gcd(up , down);
    up /= d;
    down /= d;
    cout << " " << toString(up) << "/" << toString(down) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    C[0][0] = 1;
    for(int i = 1; i < 125; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i)C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    for(int kase = 1; kase <= t; ++kase){
        cout << "Case #" << kase << ": ";
        solve();
    }
}