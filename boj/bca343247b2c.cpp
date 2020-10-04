#include <iostream>
#include <vector>
#define INF (1LL << 60)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, d;
	cin >> n >> m >> d;

	vector<vector<long long>> dp(n, vector<long long>(m, -INF));
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < m; ++i) dp[0][i] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 1; k <= min(d, n - i - 1); ++k) {
				for (int l = max(-d + k, -j); l <= min(d - k, m - j - 1); ++l) {
					dp[i + k][j + l] = max(dp[i + k][j + l], dp[i][j] + board[i][j] * board[i + k][j + l]);
				}
			}
		}
	}

	long long ans = -INF;
	for (int i = 0; i < m; ++i) ans = max(ans, dp[n - 1][i]);

	cout << ans;
}