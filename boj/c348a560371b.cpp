#include <iostream>
#define INF 987654321
using namespace std;

int arr[305][305], dp[305][305];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 1; k <= arr[i][j]; ++k) {
				if (i + k < n) dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
				if (j + k < m) dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
			}
		}
	}

	cout << dp[n - 1][m - 1];
}