#include <iostream>
using namespace std;

long long ax[2020];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 2 * n; ++i) cin >> ax[i];

	long long x, now, h = 0;
	cin >> x;

	for (int i = 0; i < n; ++i) {
		if (ax[2 * i] < x && x <= ax[2 * i + 1]) {
			now = h + x - ax[2 * i];
		}
		h += ax[2 * i + 1] - ax[2 * i];
		if (ax[2 * i + 1] < x && x <= ax[2 * i + 2]) {
			cout << h + ax[2 * i + 1];
			return 0;
		}
		h -= ax[2 * i + 2] - ax[2 * i + 1];
	}

	long long ans = 0;
	h = 0;
	for (int i = 0; i < n; ++i) {
		h += ax[2 * i + 1] - ax[2 * i];
		if (ax[2 * i + 1] < x) {
			long long top = x * h - now * ax[2 * i + 1];
			long long down = x - ax[2 * i + 1];
			if (top > 0) ans = max(ans, (top - 1) / down + 1);
		}
		h -= ax[2 * i + 2] - ax[2 * i + 1];
	}
	cout << ans;
}