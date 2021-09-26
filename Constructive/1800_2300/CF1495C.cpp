#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double ld;
const int maxv = 1e6 + 10;
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
const int mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N , M;
        cin >> N >> M;
        vector<vector<char>> a(N + 1 , vector<char>(M + 1));
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= N; i += 3){
            for(int j = 1; j <= M; ++j){
                a[i][j] = 'X';
            }
        }
        for(int i = 1; i <= N; i += 3){
            if(i + 2 > N)break;
            int f1 = 0 , f2 = 0;
            for(int j = 1; j <= M; ++j){
                if(a[i + 1][j] == 'X' && f1 == 0)f1 = j;
                if(a[i + 2][j] == 'X' && f2 == 0)f2 = j;
            }
            if(f1 == 0 && f2 == 0){
                a[i + 1][1] = a[i + 2][1] = 'X';
            }
            if(f1 > 0 && f2 > 0){
                a[i + 2][f1] = 'X';
            }
            if(f1 == 0 && f2 > 0){
                a[i + 1][f2] = 'X';
            }
            if(f1 > 0 && f2 == 0){
                a[i + 2][f1] = 'X';
            }
        }
        if(N % 3 == 0){
            for(int j = 1; j <= M; ++j){
                if(a[N][j] == 'X'){
                    a[N - 1][j] = 'X';
                }
            }
        }
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                cout << a[i][j];
            }
            cout << endl;
        }
    }
} 
