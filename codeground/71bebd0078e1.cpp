#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int dp[50001][101];
int sum[50001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		int n, k, l, t;
		cin >> n >> k >> l;
		vector<int> bomb(l);
		for (int i = 0; i < l; ++i) cin >> bomb[i];
		
		for (int i = 1; i <= min(n, k); ++i) sum[i] = dp[i][i] = 1;
		
		int bi = 0;
		for (int i = 1; i < n; ++i) {
			if (bi < l && i == bomb[bi]) {
				bi++;
				continue;
			}
			for (int cross = 1; cross <= k; ++cross) {
				int t = i + cross;
				if (t > n) continue;
				dp[t][cross] = (sum[i] - dp[i][cross] + MOD) % MOD;
				sum[t] = (sum[t] + dp[t][cross]) % MOD;
			}
		}
		
		cout << "Case #" << test << '\n';
		cout << sum[n] << '\n';
	}
}