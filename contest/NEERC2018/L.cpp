#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2, t;
	cin >> n1 >> t;

	vector<int> x1(n1);
	int xmin = INF, xmax = -1;
	for (int i = 0; i < n1; ++i) {
		cin >> x1[i];
		xmin = min(xmin, x1[i]);
		xmax = max(xmax, x1[i]);
	}

	cin >> n2 >> t;
	vector<int> x2(n2);
	xmin = INF, xmax = -1;
	for (int i = 0; i < n2; ++i) {
		cin >> x2[i];
		xmin = min(xmin, x2[i]);
		xmax = max(xmax, x2[i]);
	}

	int ans = 2;

	for (int inc = 2; inc <= INF; inc <<= 1) {
		map<int, int> m1, m2;
		for (int i = 0; i < n1; ++i) m1[x1[i] % inc]++;
		for (int i = 0; i < n2; ++i) m2[x2[i] % inc]++;

		for (auto it = m1.begin(); it != m1.end(); ++it) {
			int opp = (it->first + inc / 2) % inc;
			if (m2.find(opp) != m2.end()) {
				ans = max(ans, it->second + m2[opp]);
			}
			else {
				ans = max(ans, it->second);
			}
		}

		for (auto it = m2.begin(); it != m2.end(); ++it) {
			int opp = (it->first + inc / 2) % inc;
			if (m1.find(opp) != m1.end()) {
				ans = max(ans, it->second + m1[opp]);
			}
			else {
				ans = max(ans, it->second);
			}
		}
	}

	cout << ans;
}