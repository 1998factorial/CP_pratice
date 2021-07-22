#include <bits/stdc++.h>
using namespace std;

int N;
int a[105];

/*
    528
    52 
    ----
    528
    529

    422
    322
    ----
    422
    3220

    999
    9000

    989999
    990000
*/

int solve(){
    cin >> N;
    vector<string> b;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        b.push_back(to_string(a[i]));
    }
    int ans = 0;
    for(int i = 1; i < N; ++i){
        int len1 = b[i - 1].size() , len2 = b[i].size();
        if(len1 < len2)continue;
        if(len1 == len2){
            if(b[i] <= b[i - 1]){
                b[i] += '0';
                ++ans;
            }
        }
        else if(len1 > len2){
            int f = 0;
            int greater = 0;
            for(int j = 0; j < len2; ++j){
                if(b[i][j] < b[i - 1][j]){
                    f = 1;
                    for(int k = len2; k <= len1; ++k){
                        b[i] += '0';
                        ++ans;
                    }
                    break;
                }
                if(b[i][j] > b[i - 1][j]){
                    greater = 1;
                    break;
                }
            }
            if(f)continue;
            if(greater){
                for(int j = len2; j < len1; ++j){
                    b[i] += '0';
                    ++ans;
                }
                continue;
            }
            int nine_sufix = 0;
            for(int j = len1 - 1; j >= len2; --j){
                if(b[i - 1][j] == '9'){
                    ++nine_sufix;
                }
                else break;
            }
            //printf("at i = %d\n" , i);
            //printf("suf = %d\n" , nine_sufix);
            if(nine_sufix == len1 - len2){
                for(int j = len2; j <= len1; ++j){
                    b[i] += '0';
                    ++ans;
                }
                continue;
            }
            if(nine_sufix == 0){
                //printf("should add %d zeros\n" , len1 - len2);
                for(int j = len2; j < len1; ++j){
                    b[i] += b[i - 1][j];
                    if(j == len1 - 1)++b[i][j];
                    ++ans;
                }
                continue;
            }
            for(int j = len2; j < len1 - nine_sufix; ++j){
                b[i] += b[i - 1][j];
                if(j == len1 - nine_sufix - 1)++b[i][j];
                ++ans;
            }
            for(int j = len1 - nine_sufix; j < len1; ++j){
                b[i] += '0';
                ++ans;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        //cout << b[i] << endl;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int kase = 1; kase <= t; ++kase){
        cout << "Case #" << kase << ": " << solve() << endl;
    }
}