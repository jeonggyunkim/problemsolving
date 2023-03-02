#include <iostream>
#include <vector>
#define INF (1LL << 60)
using namespace std;

int a[300], b[300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	cin >> m;

	vector<long long> dp(m + 1, INF);
	dp[1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = m; j >= 0; --j) {
			if (dp[j] != INF && j + a[i] - 2 <= m) {
				dp[j + a[i] - 2] = min(dp[j + a[i] - 2], dp[j] + b[i]);
			}
		}
	}
	if (dp[m] == INF) cout << -1;
	else cout << dp[m];
}