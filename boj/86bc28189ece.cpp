#include <iostream>
#include <memory.h>
using namespace std;

int len[16];
int dp[161][2];
int temp[161][2];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> len[i];

	int ans = 0;
	for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
		memset(dp, -1, sizeof(dp));
		dp[80][0] = dp[80][1] = 0;
		for (int i = 0; i < n; ++i) {
			memcpy(temp, dp, sizeof(dp));
			int pos = (mask & (1 << i)) ? 1 : 0;
			for (int j = 0; j <= 160; ++j) {
				if (dp[j][pos] != -1) {
					if (j - len[i] >= 0) {
						temp[j - len[i]][pos] = max(temp[j - len[i]][pos], dp[j][pos] + len[i]);
					}
					if (j + len[i] <= 160) {
						temp[j + len[i]][pos] = max(temp[j + len[i]][pos], dp[j][pos]);
					}
				}
			}
			memcpy(dp, temp, sizeof(dp));
		}
		ans = max(ans, dp[80][0] * dp[80][1]);
	}
	if (ans == 0) cout << -1;
	else cout << ans;
}
