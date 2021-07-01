#include <iostream>
#define INF 987654321
using namespace std;

int dp[1000][3];
int cost[1000][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost[i][j];
		}
	}

	int ans = INF;
	for (int color = 0; color < 3; ++color) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = INF;
			}
		}
		dp[0][color] = cost[0][color];
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (dp[i - 1][j] != INF) {
					dp[i][(j + 1) % 3] = min(dp[i][(j + 1) % 3], dp[i - 1][j] + cost[i][(j + 1) % 3]);
					dp[i][(j + 2) % 3] = min(dp[i][(j + 2) % 3], dp[i - 1][j] + cost[i][(j + 2) % 3]);
				}
			}
		}
		ans = min(ans, dp[n - 1][(color + 1) % 3]);
		ans = min(ans, dp[n - 1][(color + 2) % 3]);
	}
	cout << ans;
}