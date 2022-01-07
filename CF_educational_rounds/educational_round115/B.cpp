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
const int maxv = 1e6 + 10;
const int maxn = 1e5 + 10;
const int inf32 = 1e9 + 10;
const ll inf64 = 1e18 + 10;
int a[1005][6];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= 5; ++j){
                cin >> a[i][j];
            }
        }
        int ok = 0;
        for(int x = 1; x <= 5; ++x){
            for(int y = x + 1; y <= 5; ++y){
                vector<int> good , bad;
                for(int i = 1; i <= N; ++i){
                    if(a[i][x])
                        good.push_back(i);
                    else
                        bad.push_back(i);
                }
                if(good.size() < N / 2)continue;
                int cnt = 0;
                for(int i : bad){
                    if(a[i][y])++cnt;
                }
                if(cnt < bad.size())continue;
                for(int i : good){
                    if(a[i][y])++cnt;
                }
                if(cnt < N / 2)continue;
                ok = 1;
            }
        }
        if(ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
} 