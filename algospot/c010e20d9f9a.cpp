#include <iostream>
#define EPS 1e-10
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
		unsigned int n, m;
		cin >> n >> m;

		int ratio = 100.0 * m / n;
		unsigned int low = 0, high = 2000000000, mid;

		if ((int)(100.0 * (m + high) / (n + high) + EPS) < ratio + 1) {
			cout << -1 << '\n';
			continue;
		}

		while (high - low > 1) {
			mid = (low + high) / 2;
			int r = 100.0 * (m + mid) / (n + mid) + EPS;
			if (r > ratio) high = mid;
			else low = mid;
		}

		cout << high << '\n';
	}
}
