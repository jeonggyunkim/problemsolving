#include <iostream>
#include <string>
using namespace std;

int dp[3001][3001] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	string x, y;
	cin >> x >> y;

	for (int i = 0; i <= x.size(); ++i) {
		for (int j = 0; j <= y.size(); ++j) {
			if (i == 0 || j == 0) {
				if (i == 0) dp[i][j] = j * b;
				if (j == 0) dp[i][j] = i * b;
			}
			else {
				if (x[i - 1] == y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + a;
				else dp[i][j] = dp[i - 1][j - 1] + c;
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + b);
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + b);
			}
		}
	}

	cout << dp[x.size()][y.size()];
}