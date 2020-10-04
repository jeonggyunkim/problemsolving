#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int arr[300010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n;
	char t[1010];
	for (int i = 0; i < n; ++i) cin >> t[i];

	cin >> m >> k;
	vector<vector<pair<int, char>>> edge(m);
	int a, b;
	char c;
	while (k--) {
		cin >> a >> b >> c;
		a--; b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	int dp[510][1010];
	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dp[j][i] != -1) {
				for (pair<int, char> u: edge[j]) {
					if (u.second == t[i]) dp[u.first][i + 1] = max(dp[u.first][i + 1], dp[j][i] + 10);
					else dp[u.first][i + 1] = max(dp[u.first][i + 1], dp[j][i]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		ans = max(ans, dp[i][n]);
	}

	cout << ans;
}