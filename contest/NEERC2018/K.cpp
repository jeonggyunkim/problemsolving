#include <bits/stdc++.h>
using namespace std;

int arr[5010];
int dp[5010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (dp[i - 1] != -1) {
			priority_queue<int> low;
			priority_queue<int, vector<int>, greater<int>> high;
			if (arr[i] >= m) dp[i] = max(dp[i], dp[i - 1] + 1);
			if (i + 1 <= n && min(arr[i], arr[i + 1]) >= m) dp[i + 1] = max(dp[i + 1], dp[i - 1] + 1);
			low.push(min(arr[i], arr[i + 1]));
			high.push(max(arr[i], arr[i + 1]));

			for (int j = i + 2; j <= n; ++j) {
				if ((low.size() + high.size()) % 2 == 0) {
					if (arr[j] <= low.top()) low.push(arr[j]);
					else {
						high.push(arr[j]);
						low.push(high.top());
						high.pop();
					}
				}
				else {
					if (arr[j] >= low.top()) high.push(arr[j]);
					else {
						low.push(arr[j]);
						high.push(low.top());
						low.pop();
					}
				}
				if (low.top() >= m) {
					dp[j] = max(dp[j], dp[i - 1] + 1);
				}
			}
		}
	}
	if (dp[n] == -1) cout << 0;
	else cout << dp[n];
}