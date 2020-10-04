#include <iostream>
using namespace std;

int dp[1010][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> t;
			dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + t;
		}
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}