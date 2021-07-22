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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N , M;
    cin >> N >> M;
    vector<vector<int>> ans(N + 1 , vector<int> (M + 1 , -1));
    auto inboard = [&](int x , int y) -> bool {
        return 1 <= x && x <= N && 1 <= y && y <= M;
    };
    auto check = [&](int i , int j , int len , int c) -> bool {
        if(!inboard(i + len - 1 , j + len - 1))return false;
        for(int k = 0; k < len; ++k){
            for(int l = 0; l < len; ++l){
                if(~ans[i + k][j + l])return false;
            }
        }
        for(int k = 0; k < len; ++k){
            if(inboard(i - 1 , j + k) && ans[i - 1][j + k] == c)return false;
            if(inboard(i + len , j + k) && ans[i + len][j + k] == c)return false;
            if(inboard(i + k , j - 1) && ans[i + k][j - 1] == c)return false;
            if(inboard(i + k , j + len) && ans[i + k][j + len] == c)return false;
        }
        return true;
    };
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(~ans[i][j])continue;
            set<int> s;
            if(inboard(i - 1 , j))s.insert(ans[i - 1][j]);
            if(inboard(i + 1 , j))s.insert(ans[i + 1][j]);
            if(inboard(i , j - 1))s.insert(ans[i][j - 1]);
            if(inboard(i , j + 1))s.insert(ans[i][j + 1]);
            int c = 0; // smallest colour we can put at ans[i][j]
            while(s.find(c) != s.end())++c;
            if(c == 0){
                for(int len = max(N , M); len >= 1; --len){
                    if(check(i , j , len , c)){
                        for(int k = 0; k < len; ++k){
                            for(int l = 0; l < len; ++l){
                                ans[i + k][j + l] = c;
                            }
                        }
                        break;
                    }
                }
            }
            else{
                for(int len = 1; len <= max(N , M); ++len){
                    int canput = check(i , j , len , c);
                    if(!canput)continue;
                    //cout << "we can try len = " << len << endl;
                    int ok = 0;
                    if(inboard(i , j + len) && ~ans[i][j + len]){
                        ok = 1;
                    }
                    if(!inboard(i , j + len)){
                        ok = 1;
                    }
                    if(!inboard(i + len , j)){
                        ok = 1;
                    }
                    if(inboard(i , j + len)){
                        for(int nc = 0; nc < c; ++nc){
                            if(check(i , j + len , 1 , nc)){
                                ok = 1;
                            }
                        }
                    }
                    if(ok){
                        for(int k = 0; k < len; ++k){
                            for(int l = 0; l < len; ++l){
                                ans[i + k][j + l] = c;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cout << (char)('A' + ans[i][j]);
        }
        cout << endl;
    }
}