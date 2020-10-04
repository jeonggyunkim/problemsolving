#include <iostream>
#include <algorithm>
using namespace std;

int dp[5010][5010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s, t;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());

	for	(int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << n - dp[n][n];
}