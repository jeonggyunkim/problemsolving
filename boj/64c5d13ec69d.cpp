#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	cout.precision(30);
	while (tc--) {
		double k, l;
		cin >> k >> l;

		if (l < k * M_PI_2) {
			cout << l * l / M_PI / 2 << '\n';
		}
		else {
			double low = k / 2, high = l;
			for (int i = 0; i < 100; ++i) {
				double mid = (low + high) / 2;
				double length = 2 * (M_PI - asin(k / 2 / mid)) * mid;
				if (length < l) low = mid;
				else high = mid;
			}
			double area = M_PI * low * low * (M_PI - asin(k / 2 / low)) / M_PI;
			area += sqrt(low * low - k * k / 4) * k / 2;
			cout << area << '\n';
		}
	}
}