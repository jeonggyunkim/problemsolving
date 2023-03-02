#include <iostream>
using namespace std;

int r[200], c[200];

int main() {
	int h, w, n;
	cin >> h >> w >> n;

	for (int i = 0; i < n; ++i) cin >> r[i] >> c[i];
	for (int i = 0; i < n; ++i) {
		r[n + i] = c[i];
		c[n + i] = r[i];
	}

	int ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = i + 1; j < 2 * n; ++j) {
			if (j == i + n) continue;
			if (r[i] + r[j] > h && c[i] + c[j] > w) continue;
			if (r[i] > h || r[j] > h || c[i] > w || c[j] > w) continue;
			ans = max(ans, r[i] * c[i] + r[j] * c[j]);
		}
	}
	cout << ans;
}