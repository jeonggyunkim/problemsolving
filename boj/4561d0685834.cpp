#include <iostream>
#define INF (1LL << 61)
using namespace std;

long long dp[1001][8][1001];
int board[1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> board[i][j];
		}
	}

	for (int line = 0; line <= N; ++line) {
		for (int i = 0; i < 8; ++i) {
			for (int k = 0; k <= K; ++k) {
				dp[line][i][k] = -INF;
			}
		}
	}
	dp[1][0][K] = 0;
	if (K >= 1) {
		dp[1][3][K - 1] = board[1][0] + board[1][1];
		dp[1][6][K - 1] = board[1][1] + board[1][2];
	}

	for (int line = 2; line <= N; ++line) {
		for (int i = 0; i < 8; ++i) {
			for (int k = 0; k <= K; ++k) {
				if (dp[line - 1][i][k] == -INF) continue;
				long long now = dp[line - 1][i][k];
				dp[line][0][k] = max(dp[line][0][k], now);
				if (k >= 1) {
					dp[line][3][k - 1] = max(dp[line][3][k - 1], now + board[line][0] + board[line][1]);
					dp[line][6][k - 1] = max(dp[line][6][k - 1], now + board[line][1] + board[line][2]);
					for (int mask = 1; mask < 8; ++mask) {
						if (i & mask) continue;
						int cnt = 0;
						for (int l = 0; l < 3; ++l) {
							if (mask & (1 << l)) {
								now += board[line - 1][l] + board[line][l];
								cnt++;
							}
						}
						if (k < cnt) {
							for (int l = 0; l < 3; ++l) {
								if (mask & (1 << l)) now -= board[line - 1][l] + board[line][l];
							}
							continue;
						}
						dp[line][mask][k - cnt] = max(dp[line][mask][k - cnt], now);
						cnt++;
						if (k >= cnt) {
							if ((mask & 3) == 0) {
								mask ^= 3;
								dp[line][mask][k - cnt] = max(dp[line][mask][k - cnt], now + board[line][0] + board[line][1]);
								mask ^= 3;
							}
							if ((mask & 6) == 0) {
								mask ^= 6;
								dp[line][mask][k - cnt] = max(dp[line][mask][k - cnt], now + board[line][1] + board[line][2]);
								mask ^= 6;
							}
						}
						for (int l = 0; l < 3; ++l) {
							if (mask & (1 << l)) now -= board[line - 1][l] + board[line][l];
						}
					}
				}
			}
		}
	}

	long long ans = -INF;
	for (int i = 0; i < 8; ++i) ans = max(ans, dp[N][i][0]);
	cout << ans;
}