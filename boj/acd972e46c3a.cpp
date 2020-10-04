#include <iostream>
using namespace std;

int arr[17][17];
int dp[17][17][3];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];

	dp[0][1][0] = 1;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		for (int k = 0; k < 3; ++k) {
			int x, y;
			if (k != 1) {
				x = i; y = j + 1;
				if (!arr[x][y]) dp[x][y][0] += dp[i][j][k];
			}
			if (k != 0) {
				x = i + 1; y = j;
				if (!arr[x][y]) dp[x][y][1] += dp[i][j][k];
			}
			x = i + 1; y = j + 1;
			if (!arr[i][y] && !arr[x][j] && !arr[x][y]) dp[x][y][2] += dp[i][j][k];
		}
	}

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}