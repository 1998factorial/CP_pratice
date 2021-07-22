#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int N , M , A[7] , B[7] , C[7][7] , dp[7][5][5][5][5][5][5];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> A[i];
    }
    for(int i = 1; i <= M; ++i){
        cin >> B[i];
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> C[i][j];
        }
    }
    for(int i = 1; i <= 6; ++i){
        for(int a = 0; a <= B[1]; ++a){
            for(int b = 0; b <= B[2]; ++b){
                for(int c = 0; c <= B[3]; ++c){
                    for(int d = 0; d <= B[4]; ++d){
                        for(int e = 0; e <= B[5]; ++e){
                            for(int f = 0; f <= B[6]; ++f){
                                dp[i][a][b][c][d][e][f] = inf;
                            }   
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; ++i){
        for(int a = 0; a <= B[1]; ++a){
            for(int b = 0; b <= B[2]; ++b){
                for(int c = 0; c <= B[3]; ++c){
                    for(int d = 0; d <= B[4]; ++d){
                        for(int e = 0; e <= B[5]; ++e){
                            for(int f = 0; f <= B[6]; ++f){
                                if(dp[i][a][b][c][d][e][f] >= inf)continue;
                                for(int da = 0; da <= a && da <= A[i + 1]; ++da){
                                    for(int db = 0; db <= b && da + db <= A[i + 1]; ++db){
                                        for(int dc = 0; dc <= c && da + db + dc <= A[i + 1]; ++dc){
                                            for(int dd = 0; dd <= d && da + db + dc + dd <= A[i + 1]; ++dd){
                                                for(int de = 0; de <= e && da + db + dc + dd + de <= A[i + 1]; ++de){
                                                    for(int df = 0; df <= f && da + db + dc + dd + de + df <= A[i + 1]; ++df){
                                                        if(da + db + dc + dd + de + df < A[i + 1])continue;
                                                        int v = 0;
                                                        if(da)v += C[i + 1][1];
                                                        if(db)v += C[i + 1][2];
                                                        if(dc)v += C[i + 1][3];
                                                        if(dd)v += C[i + 1][4];
                                                        if(de)v += C[i + 1][5];
                                                        if(df)v += C[i + 1][6];
                                                        dp[i + 1][a - da][b - db][c - dc][d - dd][e - de][f - df] = min(
                                                            dp[i + 1][a - da][b - db][c - dc][d - dd][e - de][f - df] , 
                                                            dp[i][a][b][c][d][e][f] + v
                                                        );
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = inf;
    for(int a = 0; a <= B[1]; ++a){
        for(int b = 0; b <= B[2]; ++b){
            for(int c = 0; c <= B[3]; ++c){
                for(int d = 0; d <= B[4]; ++d){
                    for(int e = 0; e <= B[5]; ++e){
                        for(int f = 0; f <= B[6]; ++f){
                            ans = min(ans , dp[N][a][b][c][d][e][f]);
                        }
                    }   
                }
            }
        }
    }
    if(ans >= inf)ans = -1;
    cout << ans << endl;
}