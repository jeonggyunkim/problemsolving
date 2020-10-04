#include <iostream>
#define MOD 1000000007
using namespace std;

long long dp[50][301][301];
char str[51];
char board[301][301];
int n, m, l;

int sum(int ind, int a, int b, int c, int d) {
	if (a < 1) a = 1;
	if (b < 1) b = 1;
	if (c > n) c = n;
	if (d > m) d = m;
	long long ret = 0;
	ret += dp[ind][c][d];
	ret -= dp[ind][a - 1][d];
	ret -= dp[ind][c][b - 1];
	ret += dp[ind][a - 1][b - 1];
	ret += 2LL * MOD;
	return ret % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> l;
	cin >> str;
	l = -1;
	while (str[++l]);
	
	for (int i = 0; i < n; ++i) cin >> board[i];

	for (int j = 1; j <= n; ++j) {
		for (int k = 1; k <= m; ++k) {
			dp[0][j][k] = dp[0][j - 1][k] + dp[0][j][k - 1] - dp[0][j - 1][k - 1];
			if (board[j - 1][k - 1] == str[0]) {
				dp[0][j][k]++;
			}
		}
	}
	for (int i = 1; i < l; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= m; ++k) {
				if (board[j - 1][k - 1] == str[i]) {
					dp[i][j][k] = sum(i - 1, 1, 1, n, m);
					dp[i][j][k] -= sum(i - 1, 1, k - 1, n, k + 1);
					dp[i][j][k] -= sum(i - 1, j - 1, 1, j + 1, m);
					dp[i][j][k] -= sum(i - 1, j - 2, k - 2, j + 2, k + 2);
					dp[i][j][k] += sum(i - 1, j - 2, k - 1, j + 2, k + 1);
					dp[i][j][k] += sum(i - 1, j - 1, k - 2, j + 1, k + 2);
				}
				dp[i][j][k] += dp[i][j - 1][k];
				dp[i][j][k] += dp[i][j][k - 1];
				dp[i][j][k] -= dp[i][j - 1][k - 1];
				(dp[i][j][k] += 2LL * MOD) %= MOD;
			}
		}
	}

	cout << dp[l - 1][n][m];
}