#include <iostream>
using namespace std;

int dp[1010][510];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt = 0;
	dp[0][0] = 1;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j <= 500; ++j) {
			if (dp[i][j]) {
				if (s[i] == '(') {
					(dp[i + 1][j] += dp[i][j]) %= 2012;
					(dp[i + 1][j + 1] += dp[i][j]) %= 2012;
				}
				else {
					int k = cnt - j;
					if (j > 0) (dp[i + 1][j - 1] += dp[i][j]) %= 2012;
					if (k > 0) (dp[i + 1][j] += dp[i][j]) %= 2012;
				}
			}
		}
		if (s[i] == '(') cnt++;
		else cnt--;
	}
	cout << dp[s.size()][0];
}