#include <iostream>
#include <memory.h>
using namespace std;

int n, k;
int w[100], v[100];

int dp[101][100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

	memset(dp, -1, sizeof(dp));
	dp[0][k] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (dp[i][j] != -1) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				if (j >= w[i]) dp[i + 1][j - w[i]] = max(dp[i + 1][j - w[i]], dp[i][j] + v[i]);
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= k; ++i) ans = max(ans, dp[n][i]);
	cout << ans;
}