#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int N , Q , a[maxn] , s[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i)cin >> a[i];
    for(int i = 1; i <= Q; ++i){
        int l , r;
        cin >> l >> r;
        ++s[l];
        --s[r + 1];
    }
    for(int i = 1; i <= N; ++i)s[i] += s[i - 1];
    sort(s + 1 , s + 1 + N);
    sort(a + 1 , a + 1 + N);
    ll ans = 0;
    for(int i = 1; i <= N; ++i)ans += (ll)s[i] * a[i];
    cout << ans << endl;
}