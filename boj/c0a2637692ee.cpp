#include <iostream>
using namespace std;

typedef unsigned long long ull;

int m;
int ans[64];
ull dp[3][3][64];

void rec(int i, int j, int n, ull K) {
	int k = 3 - i - j;
	if (m == 1) {
		if (n == 1) {
			if (K == 0) ans[n] = i;
			else ans[n] = j;
			return;
		}
		if (K <= dp[i][k][n - 1]) {
			ans[n] = i;
			rec(i, k, n - 1, K);
		}
		else {
			ans[n] = j;
			rec(k, j, n - 1, K - dp[i][k][n - 1] - 1);
		}
	}
	else {
		if (n == 1) {
			if ((m == 2 && abs(i - j) == 2) || (m == 3 && (j - i + 3) % 3 == 2)) {
				if (K == 0) ans[n] = i;
				else if (K == 1) ans[n] = k;
				else ans[n] = j;
			}
			else {
				if (K == 0) ans[n] = i;
				else ans[n] = j;
			}
			return;
		}
		if ((m == 2 && abs(i - j) == 2) || (m == 3 && (j - i + 3) % 3 == 2)) {
			if (K <= dp[i][j][n - 1]) {
				ans[n] = i;
				rec(i, j, n - 1, K);
			}
			else if (K <= dp[i][j][n - 1] + 1 + dp[j][i][n - 1]) {
				ans[n] = k;
				rec(j, i, n - 1, K - dp[i][j][n - 1] - 1);
			}
			else {
				ans[n] = j;
				rec(i, j, n - 1, K - dp[i][j][n - 1] - 1 - dp[j][i][n - 1] - 1);
			}
		}
		else {
			if (K <= dp[i][k][n - 1]) {
				ans[n] = i;
				rec(i, k, n - 1, K);
			}
			else {
				ans[n] = j;
				rec(k, j, n - 1, K - dp[i][k][n - 1] - 1);
			}
		}
	}
}

int main() {
	ull n, K;
	cin >> m >> n >> K;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != j) {
				if (m == 1) dp[i][j][1] = 1;
				else if (m == 2) dp[i][j][1] = abs(i - j);
				else dp[i][j][1] = (j - i + 3) % 3;
			}
		}
	}

	for (int l = 2; l <= 60; ++l) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (i != j) {
					int k = 3 - i - j;
					if (m == 1) dp[i][j][l] = dp[i][k][l - 1] + dp[k][j][l - 1] + 1;
					else {
						if ((m == 2 && abs(i - j) == 2) || (m == 3 && (j - i + 3) % 3 == 2)) dp[i][j][l] = dp[i][j][l - 1] + 1 + dp[j][i][l - 1] + 1 + dp[i][j][l - 1];
						else dp[i][j][l] = dp[i][k][l - 1] + 1 + dp[k][j][l - 1];
					}
				}
			}
		}
	}

	rec(0, 2, n, K);
	for (int i = 1; i <= n; ++i) cout << ans[i] + 1 << ' ';
}