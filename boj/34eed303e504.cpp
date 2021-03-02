#include <iostream>
#include <vector>
using namespace std;

int d[100], x[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> d[i];
	x[0] = d[0];

	for (int i = 1; i < n; ++i) {
		int mx = -1;
		for (int j = 0; j < i; ++j) {
			if (d[i] > d[j]) {
				mx = max(mx, x[j] + 2 * d[j]);
			}
			else {
				mx = max(mx, x[j] + 2 * d[i]);
			}
		}
		x[i] = mx;
	}
	for (int i = 0; i < n; ++i) {
		vector<bool> r(d[i] * 2, 1);
		int start = x[i] - d[i];
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (d[i] >= d[j]) continue;
			for (int k = x[j] - d[j]; k < x[j] + d[j]; ++k) {
				if (k >= start && k < start + 2 * d[i]) {
					r[k - start] = 0;
				}
			}
		}
		bool pos = 0;
		for (bool b: r) pos |= b;
		if (pos) cout << i + 1 << ' ';
	}
}