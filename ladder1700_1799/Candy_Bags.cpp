#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int N;
    cin >> N;
    vector<vector<int>> ans(N + 1 , vector<int>(N + 1));
    int cnt = 1;
    for(int j = 1; j <= N; ++j){
        if(j & 1){
            for(int i = 1; i <= N; ++i){
                ans[i][j] = cnt++;
            }
        }
        else{
            for(int i = N; i >= 1; --i){
                ans[i][j] = cnt++;
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

