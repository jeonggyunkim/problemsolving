#include <iostream>
#include <memory.h>
using namespace std;

int dp[100010][3][21];
int what[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, K;
	cin >> n >> K;

	char c;
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		if (c == 'H') what[i] = 0;
		else if (c == 'P') what[i] = 1;
		else what[i] = 2;
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < 3; ++i) dp[0][i][K] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (j == what[i + 1]) {
				for (int k = 0; k <= K; ++k) {
					if (dp[i][j][k] == -1) continue;
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + 1);
				}
			}
			else {
				for (int k = 0; k <= K; ++k) {
					if (dp[i][j][k] == -1) continue;
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
					if (k != 0) dp[i + 1][what[i + 1]][k - 1] = max(dp[i + 1][what[i + 1]][k - 1], dp[i][j][k] + 1);
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= K; ++i) {
		for (int j = 0; j < 3; ++j) {
			ans = max(ans, dp[n][j][i]);
		}
	}
	cout << ans;
}
