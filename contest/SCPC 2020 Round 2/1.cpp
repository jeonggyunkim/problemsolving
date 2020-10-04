#include <bits/stdc++.h>
#define INF (1LL << 60)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n;
		cin >> n;

		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		vector<vector<long long>> dp(n + 1, vector<long long>(4, INF));

		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = min(dp[i][0], dp[i - 1][0] + abs(a[i - 1] - b[i - 1]));

			dp[i][1] = min(dp[i][1], dp[i - 1][0]);
			if (i != 1) dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(a[i - 1] - b[i - 2]));

			dp[i][2] = min(dp[i][2], dp[i - 1][0]);
			if (i != 1) dp[i][2] = min(dp[i][2], dp[i - 1][2] + abs(a[i - 2] - b[i - 1]));

			dp[i][3] = min(dp[i][3], dp[i - 1][0]);
			dp[i][3] = min(dp[i][3], dp[i][1]);
			dp[i][3] = min(dp[i][3], dp[i][2]);
			dp[i][3] = min(dp[i][3], dp[i - 1][3] + abs(a[i - 1] - b[i - 1]));
		}

		cout << "Case #" << test << '\n';
		cout << dp[n][3] << '\n';
	}
}