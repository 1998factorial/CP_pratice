#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll INF = -1e18;
 
void solve() {
    int n, m, k, cnt = 1, a, b, c, d, h, e;
    cin >> n >> m >> k;
    int t[n + 1];
    vector<ll> dp(k * 2 + 3, INF);
    vector<array<int, 2>> to(k * 2 + 3);
    vector<vector<array<int, 2>>> row(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    row[1].push_back({1, cnt++});
    dp[1] = 0;
    while (k--) {
        cin >> a >> b >> c >> d >> h;
        dp[cnt] = INF;
        row[a].push_back({b, cnt++});
        dp[cnt] = INF;
        row[c].push_back({d, cnt++});
        to[cnt - 2] = {cnt - 1, h};
    }
    dp[cnt] = INF;
    row[n].push_back({m, cnt});
    for (int i = 1; i <= n; ++i) {
        e = row[i].size();
        sort(row[i].begin(), row[i].end());
        for (int j = 1; j < e; ++j)
            dp[row[i][j][1]] = max(dp[row[i][j][1]], dp[row[i][j - 1][1]] + 1LL * t[i] * (row[i][j - 1][0] - row[i][j][0]));
        for (int j = e - 2; j >= 0; --j)
            dp[row[i][j][1]] = max(dp[row[i][j][1]], dp[row[i][j + 1][1]] + 1LL * t[i] * (row[i][j][0] - row[i][j + 1][0]));

        for (auto j : row[i])
            if (to[j[1]][0] && dp[j[1]] != INF)
                dp[to[j[1]][0]] = max(dp[to[j[1]][0]], dp[j[1]] + to[j[1]][1]);
    }
    if (dp[cnt] == INF)
        cout << "NO ESCAPE\n";
    else
        cout << - dp[cnt] << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}