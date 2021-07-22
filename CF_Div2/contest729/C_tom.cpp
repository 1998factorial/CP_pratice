#include <bits/stdc++.h>
#define int int64_t
#define MOD ((int) 1e9+7)
#define ID if (false)
using namespace std;

vector<int> cv;
vector<int> cp;
vector<int> sum;

int gcd(int x , int y){
	return x == 0 ? y : gcd(y % x , x);
}

int m(int x) {
	return x % MOD;
}

int calc(int len) {
	if (len == 0) return 0;
	int lg = 0;
	while (cp[lg+1] <= len) lg += 1;
	return m(m((len/cp[lg]) * sum[lg]) + calc(len%cp[lg]));
}

int t, n;
int32_t main() {
	int last_first_appear = -1;
	for (int i = 2; i <= 100; i++) {
		int first_appear = 1;
		for (int j = 1; j < i; j++) {
			first_appear /= gcd(first_appear, j);
			first_appear *= j;
		}
		if (first_appear != last_first_appear) {
			cv.push_back(i);
			cp.push_back(first_appear);
			sum.push_back(0);
		}
		if (first_appear > 1e16) break;
	}

	sum[0] = cv[0];
	sum[1] = cv[1] + cv[0];
	for (int i = 2; i < cv.size(); i++) {
		sum[i] = m(sum[i-1]) * m(cp[i]/cp[i-1]) + (cv[i]-cv[i-1]);
		sum[i] = m(sum[i]);
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << calc(n) << endl;
	}
}
