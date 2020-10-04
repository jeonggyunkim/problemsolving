#include <iostream>
#include <memory.h>
using namespace std;

int dp[1000][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int w, t;
	for (int i = 0; i < k; ++i) {
		cin >> w >> t;
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j] != -1) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				if (j + t <= n) dp[i + 1][j + t] = max(dp[i + 1][j + t], dp[i][j] + w);
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, dp[k][i]);
	}

	cout << ans;
}