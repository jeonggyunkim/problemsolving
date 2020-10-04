
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int R, s, e;
		cin >> R >> s >> e;

		int n;
		cin >> n;

		vector<int> l(n);
		vector<int> r(n);
		vector<int> h(n);
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i] >> h[i];
		}
		vector<double> d(n + 1);
		for (int i = 0; i < n - 1; ++i) d[i + 1] = l[i + 1] - r[i];
		d[0] = l[0] - s;
		d[n] = e - r[n - 1];

		double v, c;
		double ans = 0.0;
		for (int i = 0; i < n; ++i) {
			if (h[i] > R) {
				v = R;
				c = (M_PI / 2) * R;
			}
			else {
				v = sqrt(R * R - (R - h[i]) * (R - h[i]));
				c = (M_PI / 2 - asin((double)(R - h[i]) / R)) * R;
			}
			d[i] -= v;
			d[i + 1] -= v;
			ans += 2 * max(0, h[i] - R);
			ans += 2 * c;
			ans += r[i] - l[i];
		}
		for (int i = 0; i <= n; ++i) ans += d[i];

		cout.precision(15);
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
