#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dp[1001][1001] = {};
	string a, b;
	cin >> a >> b;

	for (int i = 1; i <= a.length(); ++i) for (int j = 1; j <= b.length(); ++j) {
		if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
		else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	}

	int i = a.length(), j = b.length();
	cout << dp[i][j] << '\n';
	string ans;
	while (dp[i][j] != 0) {
		if (a[i-1] == b[j-1]) {
			ans += a[i-1];
			i--;
			j--;
		}
		else if (dp[i][j] == dp[i-1][j]) i--;
		else j--;
	}

	reverse(ans.begin(), ans.end());
	cout << ans;
}