#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, b, t;
	cin >> n >> m >> b;

	int cnt[257] = {};
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> t;
		cnt[t]++;
	}

	int ans, mint = 987654321;
	for (int h = 256; h >= 0; --h) {
		int need = 0, gain = 0;
		for (int i = 0; i < h; ++i) need += (h - i) * cnt[i];
		for (int i = 256; i > h; --i) gain += (i - h) * cnt[i];

		t = need + gain * 2;
		if (need <= gain + b) {
			if (t < mint) {
				mint = t;
				ans = h;
			}
		}
	}
	cout << mint << ' ' << ans;
}