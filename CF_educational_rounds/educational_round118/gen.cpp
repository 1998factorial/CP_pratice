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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cout << t << endl;
    while(t--){
        int N = 100000 , M = 1;
        cout << N << " " << M << endl;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(i == N - 1 && j == M - 1)cout << "L";
                else cout << ".";
            }
            cout << endl;
        }
    }
}