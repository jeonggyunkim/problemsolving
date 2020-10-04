
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	vector<int> dp(10001, INF);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 10000; ++i) {
		int n = 1;
		int sum = 1;
		while (sum <= i) {
			dp[i] = min(dp[i], n + dp[i - sum]);
			n++;
			sum += n;
		}
	}

	for (int test = 1; test <= tc; ++test) {
		int x, y;
		cin >> x >> y;

		int ans = -1;
		for (int i = x; i <= y; ++i) {
			ans = max(ans, dp[i]);
		}

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}
