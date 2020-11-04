#include <iostream>
using namespace std;

int board[20][20];
int dp[400][400][10];
int loc[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, L;
	cin >> n >> L;

	if (L == 1) {
		cout << n * n;
		return 0;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> board[i][j];
	}

	for (int i = 0; i < n * n; ++i) {
		for (int j = 0; j < n * n; ++j) {
			if (board[i / n][i % n] == board[j / n][j % n]) {
				dp[i][j][1] = 1;
			}
		}
	}
	
	for (int now = 2; now <= L / 2; ++now) {
		for (int i = 0; i < n * n; ++i) {
			for (int j = 0; j < n * n; ++j) {
				if (board[i / n][i % n] == board[j / n][j % n]) {
					for (int k = 0; k < 8; ++k) {
						int x = i / n + loc[k][0];
						int y = i % n + loc[k][1];
						if (x < 0 || x >= n || y < 0 || y >= n) continue;
						for (int l = 0; l < 8; ++l) {
							int p = j / n + loc[l][0];
							int q = j % n + loc[l][1];
							if (p < 0 || p >= n || q < 0 || q >= n) continue;
							dp[i][j][now] += dp[x * n + y][p * n + q][now - 1];
						}
					}
				}
			}
		}
	}

	int ans = 0;
	if (L & 1) {
		for (int i = 0; i < n * n; ++i) {
			for (int k = 0; k < 8; ++k) {
				int x = i / n + loc[k][0];
				int y = i % n + loc[k][1];
				if (x < 0 || x >= n || y < 0 || y >= n) continue;
				for (int l = 0; l < 8; ++l) {
					int p = i / n + loc[l][0];
					int q = i % n + loc[l][1];
					if (p < 0 || p >= n || q < 0 || q >= n) continue;
					ans += dp[x * n + y][p * n + q][L / 2];
				}
			}
		}
	}
	else {
		for (int i = 0; i < n * n; ++i) {
			int x = i / n;
			int y = i % n;
			for (int k = 0; k < 8; ++k) {
				int xx = x + loc[k][0];
				int yy = y + loc[k][1];
				if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
				ans += dp[i][xx * n + yy][L / 2];
			}
		}
	}
	cout << ans;
}