#include <iostream>
#include <vector>
#define MOD 20091101
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k, t;
		cin >> n >> k;

		vector<int> sum(n + 1, 0);
		vector<int> cnt(k, 0);
		vector<int> prev(n + 1, -1);
		vector<int> lastind(k, -1);
		cnt[0]++; lastind[0] = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> t;
			sum[i] = (sum[i - 1] + t) % k;
			cnt[sum[i]]++;
			prev[i] = lastind[sum[i]];
			lastind[sum[i]] = i;
		}

		int ans1 = 0;
		for (int i = 0; i < k; ++i) {
			ans1 = ((long long)cnt[i] * (cnt[i] - 1) / 2 + ans1) % MOD;
		}

		vector<int> dp(n + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if (prev[i] == -1) dp[i] = dp[i - 1];
			else {
				dp[i] = max(dp[i - 1], 1 + dp[prev[i]]);
			}
		}

		cout << ans1 << ' ' << dp[n] << '\n';
	}
}
