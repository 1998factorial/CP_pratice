#include <bits/stdc++.h>
using namespace std;

// process right-facings from right to left
// if has left facing with same mod, will collide first with it
// otherwise if has right facing from prev with same mod, will collide with it
// otherwise survive
// do the same with left facing from left to right

#define MAXN 300005

char c;
int t, n, m, x[MAXN];
bool r[MAXN];
int answer[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) {
			cin >> c;
			r[i] = (c == 'R');
		}

		vector<int> order;
		for (int i = 1; i <= n; i++) order.push_back(i);
		sort(order.begin(), order.end(), [&](int a, int b) {
			return x[a] < x[b];
		});

		for (int i = 1; i <= n; i++) answer[i] = 0;

		// process from right to left
		deque<int> sl[2];
		deque<int> sr[2];
		reverse(order.begin(), order.end());
		for (int i : order) {
			int mod = x[i]%2;
			if (!r[i]) {
				sl[mod].push_front(i);
			} else {
				if (sl[mod].size()) {
					int other = sl[mod].front();
					sl[mod].pop_front();
					int t = (x[other] - x[i]) / 2;
					answer[i] = t;
					answer[other] = t;
				} else if (sr[mod].size()) {
					int other = sr[mod].back();
					sr[mod].pop_back();
					int t = ((m-x[other]) + (m-x[i])) / 2;
					answer[i] = t;
					answer[other] = t;
				} else {
					sr[mod].push_front(i);
				}
			}
		}

		// process from left to right
		sl[0].clear();
		sl[1].clear();
		sr[0].clear();
		sr[1].clear();
		reverse(order.begin(), order.end());
		for (int i : order) {
			int mod = x[i]%2;
			if (answer[i]) {}
			else if (r[i]) {
				sr[mod].push_back(i);
			} else {
				if (sr[mod].size()) {
					int other = sr[mod].back();
					sr[mod].pop_back();
					int t = (x[i] - x[other]) / 2;
					answer[i] = t;
					answer[other] = t;
				} else if (sl[mod].size()) {
					int other = sl[mod].front();
					sl[mod].pop_front();
					int t = (x[i] + x[other]) / 2;
					answer[i] = t;
					answer[other] = t;
				} else {
					sl[mod].push_back(i);
				}
			}
		}

		// flip all remaining Ls at origin
		// flip all remaining Rs at m
		// if they don't collide at this final round they will never collide (since total distance travel will add by 2*m)
		sl[0].clear();
		sl[1].clear();
		sr[0].clear();
		sr[1].clear();
		reverse(order.begin(), order.end());
		for (int i : order) {
			if (answer[i]) {
				continue;
			}
			if (r[i]) {
				x[i] = m + (m - x[i]);
				r[i] = false;
			} else {
				x[i] = -x[i];
				r[i] = true;
			}
			// cout << "flipped " << i << endl;
		}
		sort(order.begin(), order.end(), [&](int a, int b) {
			return x[a] < x[b];
		});
		for (int i : order) {
			int mod = x[i]%2;
			if (answer[i]) {
				continue;
			}
			// cout << "using " << i << " " << x[i] << " " << r[i] << endl;
			if (r[i]) {
				sr[abs(mod)].push_back(i);
			} else {
				if (sr[mod].size()) {
					int other = sr[mod].back();
					sr[mod].pop_back();
					int t = (x[i] - x[other]) / 2;
					answer[i] = t;
					answer[other] = t;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (answer[i] == 0) answer[i] = -1;
			cout << answer[i] << ' ';
		}
		cout << endl;
	}
}