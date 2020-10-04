#include <iostream>
using namespace std;

int m;
double n, p;
double cal(double c) {
	double ret = n;
	for (int i = 0; i < m; ++i) {
		ret *= (1 + p / 1200);
		ret -= c;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> p;

		double low = 0, high = 2 * n, mid;
		for (int i = 0; i < 100; ++i) {
			mid = (low + high) / 2;
			double t = cal(mid);
			if (t > 0) low = mid;
			else high = mid;
		}

		cout.precision(20);
		cout << mid << '\n';
	}
}
