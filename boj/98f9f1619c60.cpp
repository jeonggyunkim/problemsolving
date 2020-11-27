#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int price[5][5] = {{0, 2, 2, 2, 2}, {0, 1, 3, 4, 3}, {0, 3, 1, 3, 4}, {0, 4, 3, 1, 3}, {0, 3, 4, 3, 1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> dp(100000, vector<int>(32, INF));

	int t;
	cin >> t;
	dp[0][1 | (1 << t)] = 2;

	int cnt = 0;
	while (cin >> t, t) {
		for (int i = 0; i < 32; ++i) {
			if (dp[cnt][i] != INF) {
				if (i & (1 << t)) dp[cnt + 1][i] = min(dp[cnt][i] + 1, dp[cnt + 1][i]);
				else {
					for (int j = 0; j < 5; ++j) {
						if (i & (1 << j)) {
							int next = i ^ (1 << j);
							next ^= (1 << t);
							dp[cnt + 1][next] = min(dp[cnt][i] + price[j][t], dp[cnt + 1][next]);
						}
					}
				}
			}
		}
		cnt++;
	}

	int ans = INF;
	for (int i = 0; i < 32; ++i) {
		if (dp[cnt][i] != INF) ans = min(ans, dp[cnt][i]);
	}
	cout << ans;
}