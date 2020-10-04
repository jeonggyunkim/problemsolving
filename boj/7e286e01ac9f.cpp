#include <iostream>
#include <string>
using namespace std;

int main() {
	int dp[301][301] = {};
	int n, m;
	cin >> n >> m;

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= n; ++i) dp[i][1] = dp[i - 1][1] + abs(s1[i - 1] - s2[0]);
	for (int i = 1; i <= m; ++i) dp[1][i] = dp[1][i - 1] + abs(s1[0] - s2[i - 1]);

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + abs(s1[i - 1] - s2[j - 1]);
		}
	}
	cout << dp[n][m];
}