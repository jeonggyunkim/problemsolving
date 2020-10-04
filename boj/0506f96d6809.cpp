#include <iostream>
using namespace std;

long long dp[251][251];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 250; ++i) {
		if ((i & 1) == 0) dp[i][i / 2] = 1;
		dp[i][i] = 1;

		for (int j = 1; i - 2 * j > 0; ++j) {
			for (int k = j; k <= i - 2 * j; ++k) {
				dp[i][j] += dp[i - 2 * j][k];
			}
		}
	}

	int n;
	while (cin >> n, n) {
		long long ans = 0;
		for (int i = 1; i <= n; ++i) ans += dp[n][i];
		cout << n << ' ' << ans << '\n';
	}
}
