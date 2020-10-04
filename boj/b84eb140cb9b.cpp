#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[20][2];
int sum_x, sum_y;
double ans;

void rec(int r, int d, int s_x, int s_y) {
	if (r == 0) {
		long long x = sum_x - 2 * s_x;
		long long y = sum_y - 2 * s_y;

		ans = min(ans, sqrt(x * x + y * y));
		return;
	}
	for (int i = d; i <= n - r; ++i) {
		rec(r - 1, i + 1, s_x + arr[i][0], s_y + arr[i][1]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		ans = 1e10;
		sum_x = sum_y = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i][0] >> arr[i][1];
			sum_x += arr[i][0];
			sum_y += arr[i][1];
		}
		rec(n / 2 - 1, 1, arr[0][0], arr[0][1]);

		cout.precision(15);
		cout << ans << '\n';
	}
}