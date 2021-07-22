#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;
char a[105] , b[105] , c[105] , tmp[105];
int N1 , N2 , N3 , nex[105][26] , dp[105][105][105];
array<int , 3> pre[105][105][105];
// longest common subsequence of a and b 
// such that it does not contain c as substring

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> (a + 1);
    cin >> (b + 1);
    cin >> (c + 1);
    N1 = strlen(a + 1);
    N2 = strlen(b + 1);
    N3 = strlen(c + 1);
    for(int i = 0; i < N3; ++i){
        for(int j = 0; j < 26; ++j){
            // compute nex[i][j]
            for(int k = 1; k <= i; ++k){
                tmp[k] = c[k];
            }
            tmp[i + 1] = ('A' + j);
            for(int len = 1; len <= i + 1; ++len){
                int ok = 1;
                for(int k = 1; k <= len; ++k){
                    if(c[k] != tmp[i + 1 - len + k])ok = 0;
                }
                if(ok){
                    nex[i][j] = len;
                }
            }
        }
    }
    for(int i = 0; i <= N1; ++i){
        for(int j = 0; j <= N2; ++j){
            for(int k = 0; k <= N3; ++k){
                dp[i][j][k] = -inf;
            }
        }
    }
    for(int i = 0; i <= N1; ++i)dp[i][0][0] = 0;
    for(int i = 0; i <= N2; ++i)dp[0][i][0] = 0;
    for(int i = 0; i < N1; ++i){
        for(int j = 0; j < N2; ++j){
            for(int k = 0; k < N3; ++k){
                if(a[i + 1] == b[j + 1]){
                    int v = a[i + 1] - 'A';
                    if(nex[k][v] < N3){
                        //dp[i + 1][j + 1][nex[k][v]] = max(dp[i + 1][j + 1][nex[k][v]] , dp[i][j][k] + 1);
                        if(dp[i + 1][j + 1][nex[k][v]] < dp[i][j][k] + 1){
                            dp[i + 1][j + 1][nex[k][v]] = dp[i][j][k] + 1;
                            pre[i + 1][j + 1][nex[k][v]] = {i , j , k};
                        }
                    }
                }
                if(dp[i + 1][j + 1][k] < dp[i][j][k]){
                    dp[i + 1][j + 1][k] = dp[i][j][k];
                    pre[i + 1][j + 1][k] = {i , j , k};
                }
                if(dp[i + 1][j][k] < dp[i][j][k]){
                    dp[i + 1][j][k] = dp[i][j][k];
                    pre[i + 1][j][k] = {i , j , k};
                }
                if(dp[i][j + 1][k] < dp[i][j][k]){
                    dp[i][j + 1][k] = dp[i][j][k];
                    pre[i][j + 1][k] = {i , j , k};
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= N1; ++i){
        for(int j = 0; j <= N2; ++j){
            for(int k = 0; k < N3; ++k){
                ans = max(ans , dp[i][j][k]);
            }
        }
    }   
    if(ans <= 0){
        cout << ans << endl;
        exit(0);
    }
    int bi , bj , bk;
    for(int i = 0; i <= N1; ++i){
        for(int j = 0; j <= N2; ++j){
            for(int k = 0; k < N3; ++k){
                if(dp[i][j][k] == ans){
                    bi = i;
                    bj = j;
                    bk = k;
                    break;
                }
            }
        }
    }   
    vector<char> path;
    while(bi || bj){
        auto cur = pre[bi][bj][bk];
        int pi = cur[0] , pj = cur[1] , pk = cur[2];
        if(dp[bi][bj][bk] > dp[pi][pj][pk])path.push_back(a[bi]);
        bi = pi;
        bj = pj;
        bk = pk;
    }
    reverse(path.begin() , path.end());
    for(auto e : path)cout << e;
    cout << endl;
}