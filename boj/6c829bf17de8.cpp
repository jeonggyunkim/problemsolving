#include <iostream>
using namespace std;

char board[401][401];
int dp[401][401];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		cin >> board[i];
	}

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			if (board[i - 1][j - 1] == '.') dp[i][j]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (board[i - 1][j - 1] != '.') continue;
			for (int k = i; k <= r; ++k) {
				if (board[k - 1][j - 1] != '.') break;
				int low = j, high;
				if (dp[k][c] - dp[i - 1][c] - dp[k][j - 1] + dp[i - 1][j - 1] == (k - i + 1) * (c - j + 1)) {
					ans = max(ans, 2 * (c - j + 1 + k - i + 1) - 1);
					continue;
				}
				else high = c;

				while (high - low != 1) {
					int mid = (low + high) / 2;
					if (dp[k][mid] - dp[i - 1][mid] - dp[k][j - 1] + dp[i - 1][j - 1] == (k - i + 1) * (mid - j + 1)) {
						low = mid;
					}
					else high = mid;
				}
				ans = max(ans, 2 * (low - j + 1 + k - i + 1) - 1);
			}
		}
	}
	cout << ans;
}