#include <iostream>
#include <algorithm>
using namespace std;

int x[40], y[40], d[40];
int inside[40];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> d[i];

	int ans = 98765, x1, x2, y1, y2;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				for (int l = k; l < n; ++l) {
					x1 = min(x[i], x[j]);
					x2 = max(x[i], x[j]);
					y1 = min(y[k], y[l]);
					y2 = max(y[k], y[l]);
					int req = 2 * (x2 + y2 - x1 - y1), now = 0;
					int in = 0, cut = 0;
					for (int m = 0; m < n; ++m) {
						if (x[m] < x1 || x[m] > x2 || y[m] < y1 || y[m] > y2) {
							now += d[m];
							cut++;
						}
						else {
							inside[in++] = d[m];
						}
					}
					sort(inside, inside + in);
					while (in >= 1 && req > now) {
						now += inside[in - 1];
						in--;
						cut++;
					}
					if (req <= now) ans = min(ans, cut);
				}
			}
		}
	}
	cout << ans;
}