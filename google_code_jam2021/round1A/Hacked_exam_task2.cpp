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

bigint dp[125][125][125];

void solve(){
    int N , len;
    cin >> N >> len;
    vector<string> a(N);
    vector<int> nc(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i] >> nc[i];
    }
    if(N == 1){
        for(int i = 0; i <= len + 1; ++i){
            for(int j = 0; j <= nc[0]; ++j){
                for(int k = 0; k <= 0; ++k){
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[len + 1][0][0] = 1;
        for(int i = len; i >= 1; --i){
            for(int j = 0; j <= nc[0]; ++j){
                if(j - (a[0][i - 1] == 'T') >= 0){
                    dp[i][j][0] += dp[i + 1][j - (a[0][i - 1] == 'T')][0];
                }
                if(j - (a[0][i - 1] == 'F') >= 0){
                    dp[i][j][0] += dp[i + 1][j - (a[0][i - 1] == 'F')][0];
                }
            }
        }
        bigint up = 0 , down = dp[1][nc[0]][0];
        int x = nc[0];
        for(int l = 1; l <= len; ++l){
            for(int z = 0; z < N; ++z)swap(a[z][0] , a[z][l - 1]);
            for(int i = 0; i <= len + 1; ++i){
                for(int j = 0; j <= nc[0]; ++j){
                    for(int k = 0; k <= 0; ++k){
                        dp[i][j][k] = 0;
                    }
                }
            }
            dp[len + 1][0][0] = 1;
            for(int i = len; i >= 1; --i){
                for(int j = 0; j <= nc[0]; ++j){
                    if(j - (a[0][i - 1] == 'T') >= 0){
                        dp[i][j][0] += dp[i + 1][j - (a[0][i - 1] == 'T')][0];
                    }
                    if(j - (a[0][i - 1] == 'F') >= 0){
                        dp[i][j][0] += dp[i + 1][j - (a[0][i - 1] == 'F')][0];
                    }
                }
            }
            if(x - (a[0][0] == 'T') < 0){
                cout << 'F';
                up += dp[1][x][0];
                continue;
            }
            bigint v = dp[2][x - (a[0][0] == 'T')][0];
            if(v >= dp[1][x][0] - v){
                up += v;
                cout << 'T';
            }
            else{
                up += dp[1][x][0] - v;
                cout << 'F';
            }
            for(int z = 0; z < N; ++z)swap(a[z][0] , a[z][l - 1]);
        }
        bigint d = gcd(up , down);
        cout << " " << toString(up / d) << "/" << toString(down / d) << endl; 
    }
    if(N == 2){
        // by "linearity of expectation here", each problem can be viewed independently
        // goal is to calculate "the probability of T being the answer of question i"
        // dp[i][j][k] = the number of ways for question q[i] .. q[len] st student 1 answers 
        // j correctly and students 2 answers k correctly
        for(int i = 0; i <= len + 1; ++i){
            for(int j = 0; j <= nc[0]; ++j){
                for(int k = 0; k <= nc[1]; ++k){
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[len + 1][0][0] = 1;
        for(int i = len; i >= 1; --i){
            for(int j = 0; j <= nc[0]; ++j){
                for(int k = 0; k <= nc[1]; ++k){
                    if(j - (a[0][i - 1] == 'T') >= 0 && k - (a[1][i - 1] == 'T') >= 0){
                        dp[i][j][k] += dp[i + 1][j - (a[0][i - 1] == 'T')][k - (a[1][i - 1] == 'T')];
                    }
                    if(j - (a[0][i - 1] == 'F') >= 0 && k - (a[1][i - 1] == 'F') >= 0){
                        dp[i][j][k] += dp[i + 1][j - (a[0][i - 1] == 'F')][k - (a[1][i - 1] == 'F')];
                    }
                }
            }
        }
        int x = nc[0] , y = nc[1];
        bigint up = 0 , down = dp[1][x][y];
        for(int l = 1; l <= len; ++l){
            for(int z = 0; z < N; ++z)swap(a[z][0] , a[z][l - 1]);
            for(int i = 0; i <= len + 1; ++i){
                for(int j = 0; j <= nc[0]; ++j){
                    for(int k = 0; k <= nc[1]; ++k){
                        dp[i][j][k] = 0;
                    }
                }
            }
            dp[len + 1][0][0] = 1;
            for(int i = len; i >= 1; --i){
                for(int j = 0; j <= nc[0]; ++j){
                    for(int k = 0; k <= nc[1]; ++k){
                        if(j - (a[0][i - 1] == 'T') >= 0 && k - (a[1][i - 1] == 'T') >= 0){
                            dp[i][j][k] += dp[i + 1][j - (a[0][i - 1] == 'T')][k - (a[1][i - 1] == 'T')];
                        }
                        if(j - (a[0][i - 1] == 'F') >= 0 && k - (a[1][i - 1] == 'F') >= 0){
                            dp[i][j][k] += dp[i + 1][j - (a[0][i - 1] == 'F')][k - (a[1][i - 1] == 'F')];
                        }
                        //cout << "dp[" << i << "][" << j << "][" << k << "] = " << toString(dp[i][j][k]) << endl;
                    }
                }
            }
            if(x - (a[0][0] == 'T') < 0 || y - (a[1][0] == 'T') < 0){
                up += dp[1][x][y];
                cout << 'F';
                continue;
            }
            bigint v = dp[2][x - (a[0][0] == 'T')][y - (a[1][0] == 'T')];
            if(v >= dp[1][x][y] - v){
                cout << 'T';
                up += v;
            }
            else{
                cout << 'F';
                up += dp[1][x][y] - v;
            }
            for(int z = 0; z < N; ++z)swap(a[z][0] , a[z][l - 1]);
        }
        bigint d = gcd(up , down);
        cout << " " << toString(up / d) << "/" << toString(down / d) << endl; 
    }
    if(N > 2){
        // task 3
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int kase = 1; kase <= t; ++kase){
        cout << "Case #" << kase << ": ";
        solve();
    }
}