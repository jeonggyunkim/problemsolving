#include <iostream>
#include <memory.h>
using namespace std;

int arr[1003][1003];
int dp[1003][1003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= m + 1; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[j][i] = i != 1 ? dp[j][i - 2] + arr[j][i - 1] : 0;
			dp[j][i] = max(dp[j][i], dp[j + 1][i - 1]);
			dp[j][i] = max(dp[j][i], dp[j - 1][i - 1]);
			dp[j][i] += arr[j][i];
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; ++i) ans = max(ans, dp[i][m + 1]);

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			dp[j][i] = max(dp[j - 1][i - 1] + arr[j][i], dp[j + 1][i - 1] + arr[j + 1][i]);
		}
	}
	for (int i = 1; i <= n + 1; ++i) ans = max(ans, dp[i][m]);

	cout << ans;
}
