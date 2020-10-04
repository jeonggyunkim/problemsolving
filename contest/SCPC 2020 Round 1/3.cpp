#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for (int test = 1; test <= tc; ++test) {
		int n, k, m;
		cin >> n >> k >> m;

		vector<vector<int>> dp(n, vector<int>(n, INF));
		vector<ii> garo;
		int a, b;
		for (int i = 0; i < k; ++i) {
			cin >> a >> b;
			a--; b--;
			garo.push_back({a, b});
		}

		for (int i = 0; i < n; ++i) dp[i][i] = 0;

		for (int i = k - 1; i >= 0; --i) {
			vector<int> s = dp[garo[i].second];
			vector<int> t = dp[garo[i].first];
			for (int j = 0; j < n; ++j) {
				s[j] = min(s[j], dp[garo[i].first][j] + 1);
				t[j] = min(t[j], dp[garo[i].second][j] + 1);
			}
			dp[garo[i].first] = s;
			dp[garo[i].second] = t;
		}

		long long ans = 0;
		while (m--) {
			cin >> a >> b;
			a--; b--;
			if (dp[a][b] == INF) ans += -1;
			else ans += dp[a][b];
		}
		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}