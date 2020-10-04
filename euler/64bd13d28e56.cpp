#include <iostream>
using namespace std;

int dp[20][20];

int main() {
	freopen("in", "rt", stdin);

	int ans = -1, t;
	for (int i = 1; i <= 15; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> t;
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + t;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;
}