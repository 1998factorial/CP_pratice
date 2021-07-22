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
int N , M , x , y , a , b;
int solve(int ni , int nj){
    if(x == ni && y == nj)return 0;
    int ans = inf32;
    if(abs(x - ni) % a != 0)return ans;
    if(abs(y - nj) % b != 0)return ans;
    if(x + a > N && x - a <= 0)return ans;
    if(y + b > M && y - b <= 0)return ans;
    if((abs(x - ni) / a) % 2 != (abs(y - nj) / b) % 2)return ans;
    ans = max(abs(x - ni) / a , abs(y - nj) / b);
    return ans;
    /*
        di = x - ni = ak
        dj = y - nj = bt
        (k+) + (ans - (k+)) = k 
        (t+) + (ans - (t+)) = t
    */
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> x >> y >> a >> b;
    int ans = inf32;
    ans = min(ans , solve(1 , M));
    ans = min(ans , solve(N , 1));
    ans = min(ans , solve(1 , 1));
    ans = min(ans , solve(N , M));
    if(ans >= inf32){
        cout << "Poor Inna and pony!" << endl;
    }
    else{
        cout << ans << endl;
    }
}