#include <iostream>
using namespace std;

int dp[2010][2010];
int h[2010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> h[i];

	dp[1][0] = h[1];
	dp[0][1] = h[n];

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[j + 1][i - j] = max(dp[j + 1][i - j], dp[j][i - j] + (i + 1) * h[j + 1]);
			dp[j][i - j + 1] = max(dp[j][i - j + 1], dp[j][i - j] + (i + 1) * h[n - i + j]);
		}
	}

	int ans = -1;
	for (int j = 0; j <= n; ++j) {
		ans = max(ans, dp[j][n - j]);
	}

	cout << ans;
}