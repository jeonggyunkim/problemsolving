#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long dp[51][51][2510];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k % 2) {
		cout << 0;
		return 0;
	}
	k /= 2;

	dp[1][0][0] = 1;
	dp[1][1][1] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= i * i; ++k) {
				if (dp[i][j][k]) {
					long long t = dp[i][j][k];
					(dp[i + 1][j][k + j] += t) %= MOD;;
					(dp[i + 1][j + 1][k + j + 1] += t) %= MOD;
					if (j) {
						(dp[i + 1][j][k + j] += t * 2 * j) %= MOD;
						(dp[i + 1][j - 1][k + j - 1] += t * j * j) %= MOD;
					}
				}
			}
		}
	}
	cout << dp[n][0][k];
}