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
const int inf32 = 1e9;
const ll inf64 = 1e18;
const ll mod = 1e9 + 7;
int a[maxn] , N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= N; ++i){
        int ans = 0;
        for(int l = 1; l <= i; ++l){
            for(int r = i; r <= N; ++r){
                int cntM = 0 , cntL = 0 , cntR = 0;
                for(int j = l; j <= r; ++j){
                    if(i == j)continue;
                    if(a[j] < a[i])++cntL;
                    if(a[j] == a[i])++cntM;
                    if(a[j] > a[i])++cntR;
                }
                int mid = (cntL + cntR + cntM + 3) / 2;
                int v1 = (cntM + cntR - cntL + 1) / 2;//mid - (cntL + 1);
                int v2 = (cntL + cntM - cntR) / 2;//(cntL + cntM + 1) - mid;
                //int val = max((cntL + cntM - cntR) / 2 , (cntR + cntM - cntL + 1) / 2);
                int val = max(v1 , v2);
                ans = max(ans , val);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    for(int x = 0; x < 2; ++x){
        for(int y = 0; y < 2; ++y){
            for(int z = 0; z < 2; ++z){
                int v1 = (x + y + 1) - (x + y + z + 3) / 2;
                int v2 = (x + y - z) / 2;
                if(x + y - z < 0){
                    v2 = -(-(x + y - z) + 1) / 2;
                }
                assert(v1 == v2);
            }
        }
    }
}