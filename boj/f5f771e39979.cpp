#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, kk;
	cin >> n >> kk;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + arr[i];
	}

	double ans = 1e10;
	for (int k = kk; k <= n; ++k) {
		for (int i = 0; i <= n - k; ++i) {
			int s = sum[i + k] - sum[i];
			double ave = (double)s / k;
			double v = 0;
			for (int j = 0; j < k; ++j) {
				v += (arr[i + j + 1] - ave) * (arr[i + j + 1] - ave);
			}
			v /= k;

			ans = min(ans, sqrt(v));
		}
	}

	cout.precision(20);
	cout << ans;
}
