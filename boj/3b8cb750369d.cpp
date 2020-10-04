#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long maxd = -1;
	long long x, y;
	vector<double> v;
	while (n--) {
		cin >> x >> y;
		long long d = x * x + y * y;
		if (maxd <= d) {
			if (maxd < d) {
				maxd = d;
				v.clear();
			}
			v.push_back(atan2(y, x) * 180 / M_PI);
		}
	}

	sort(v.begin(), v.end());
	if (v.size() == 1) {
		cout << 360;
		return 0;
	}
	double ans = v[0] - v[v.size() - 1] + 360;
	for (int i = 0; i < v.size() - 1; ++i) {
		ans = max(ans, v[i + 1] - v[i]);
	}
	cout.precision(15);
	cout << ans;
}
