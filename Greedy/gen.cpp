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
    srand(time(NULL));
    int t = 10;
    cout << t << endl;
    while(t--){
        int N = 5 , D = 0;
        cout << N << " " << D << endl;
        for(int i = 1; i <= N; ++i){
            cout << rand() % 10 + 1 << " " << rand() % 10 + 1 << endl;
        }
        cout << "\n\n\n";
    }
}