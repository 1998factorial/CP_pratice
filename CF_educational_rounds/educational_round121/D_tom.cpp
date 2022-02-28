#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define x first
#define y second
#define MAXN 200005
int t, n;
int a[MAXN];
int bsle(vector<ii>& pairs, int cap) {
    int best = -1;
    int lo = 0;
    int hi = ((int) pairs.size())-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (pairs[mid].y <= cap) {
            best = mid;
            lo = mid+1;
        } 
        else {
            hi = mid-1;
        }
    }
    return best;
}
int solve() {
    sort(a+1, a+n+1);
    vector<ii> pairs;
    for (int i = 2; i <= n; i++) {
        if (a[i-1] != a[i]) {
            pairs.emplace_back(a[i-1], i-1);
        }
    }
    pairs.emplace_back(a[n], n);
    int answer = INT_MAX;
    int up = ceil(log2(n)) + 1;
    for (int a = 0; a <= up; a++) {
        for (int b = 0; b <= up; b++) {
            for (int c = 0; c <= up; c++) {
                int at = bsle(pairs, (1<<a));
                int ac = at == -1 ? 0 : pairs[at].y;
                int bt = bsle(pairs, ac+(1<<b));
                int bc = bt <= at ? 0 : pairs[bt].y - ac;
                int cc = (n-ac-bc);
                if (cc <= (1<<c)) {
                    int potential = (((1<<a)-ac)+((1<<b)-bc)+((1<<c)-cc));
                    if (potential < answer) {
                        answer = potential;
                    }
                }
            }
        }
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << solve() << endl;
    }
}