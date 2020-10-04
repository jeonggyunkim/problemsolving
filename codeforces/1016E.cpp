#include <bits/stdc++.h>
#define EPS 1e-10
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s_y, a, b;
	cin >> s_y >> a >> b;

	int n;
	cin >> n;
	vector<int> fence(2 * n);
	for (int i = 0; i < 2 * n; ++i) cin >> fence[i];
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + fence[2 * i - 1] - fence[2 * i - 2];

	int q;
	cin >> q;

	cout.precision(10);
	while (q--) {
		int x, y;
		cin >> x >> y;
		double x_l = x, x_r = x;
		x_l -= (double)(x - a) * y / (y - s_y);
		x_r += (double)(b - x) * y / (y - s_y);

		int loc1 = lower_bound(fence.begin(), fence.end(), x_l - EPS) - fence.begin();
		int loc2 = lower_bound(fence.begin(), fence.end(), x_r - EPS) - fence.begin();

		double len;
		if (loc2 >= 2 * n) len = sum[n];
		else if (loc2 & 1) {
			len = sum[loc2 / 2 + 1];
			len -= fence[loc2] - x_r;
		}
		else len = sum[loc2 / 2];

		if (loc1 >= 2 * n) len -= sum[n];
		else if (loc1 & 1) {
			len -= sum[loc1 / 2];
			len -= x_l - fence[loc1 - 1];
		}
		else len -= sum[loc1 / 2];

		len *= y - s_y;
		len /= y;

		cout << len << '\n';
	}
}