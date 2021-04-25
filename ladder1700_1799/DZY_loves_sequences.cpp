#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn] , N , dp1[maxn] , dp2[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= N; ++i){
        dp1[i] = 1;
        if(a[i] > a[i - 1])dp1[i] += dp1[i - 1];
    }
    for(int i = N; i >= 1; --i){
        dp2[i] = 1;
        if(a[i] < a[i + 1])dp2[i] += dp2[i + 1];
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i)ans = max(ans , dp1[i]);
    for(int i = 1; i <= N; ++i){
        int v = 0;
        if(a[i + 1] - a[i - 1] > 1){
            v = dp1[i - 1] + 1 + dp2[i + 1];
        }
        else{
            v = max(dp1[i - 1] + 1 , dp2[i + 1] + 1);
        }
        ans = max(ans , v);
    }
    cout << ans << endl;
}