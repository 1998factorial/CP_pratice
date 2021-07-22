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
const int maxn = 2e5 + 10;
const int inf32 = 1e9 + 10000;
const ll inf64 = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        vector<int> x(N , 0) , y(N , 0);
        for(int i = 0; i < N; ++i)cin >> x[i];
        for(int i = 0; i < 30; ++i){
            int seen_one = 0;
            for(int j = 0; j < N; ++j){
                if(x[j] >> i & 1){
                    if(!seen_one){
                        seen_one = 1;
                    }
                }
                else{
                    if(!seen_one)continue;
                    y[j] |= (1 << i);
                }
            }
        }
        for(int i : y)cout << i << " ";
        cout << endl;
    }
}   
