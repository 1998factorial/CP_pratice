#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll A;
char a[4005];
int b[4005];
int sum[4005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A;
    cin >> (a + 1);
    N = strlen(a + 1);
    for(int i = 1; i <= N; ++i)b[i] = a[i] - '0';
    for(int i = 1; i <= N; ++i){
        sum[i] = sum[i - 1] + b[i];
    }
    ll ans = 0;
    map<ll , ll> cnt;
    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; ++j){
            ll v = sum[j] - sum[i - 1];
            ++cnt[v];
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; ++j){
            ll v = sum[j] - sum[i - 1];
            if(v == 0){
                if(A > 0)continue;
                ans += (ll)N * (N + 1) / 2;
            }
            else{
                if(A % v == 0){
                    ans += cnt[A / v];
                }
            }
        }
    }
    cout << ans << endl;
}