#include <iostream>
#define INF 987654321
using namespace std;

int arr[1010];
int dp[1010][210][11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) cin >> arr[i];

	for (int i = 0; i < 1010; ++i) {
		for (int j = 0; j < 210; ++j) {
			for (int k = 0; k < 11; ++k) {
				dp[i][j][k] = INF;
			}
		}
	}

	for (int i = arr[1]; i <= 10; ++i) {
		int d = i - arr[1];
		if (m - d >= 0) dp[1][m - d][i] = 0;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = arr[i]; k <= 10; ++k) {
				int d = k - arr[i];
				for (int l = 0; l <= 10; ++l) {
					if (l <= k) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + d][l]);
					else {
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + d][l] + (l - k) * (l - k));
					}
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= 10; ++j) {
			ans = min(ans, dp[n][i][j]);
		}
	}
	cout << ans;
}