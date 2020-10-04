#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long dp[101][101][101] = {};

	int n, l, r;
	cin >> n >> l >> r;

	dp[1][1][1] = 1;
	for (int i = 1; i < n; ++i) {
		for (int l = 1; l <= i; ++l) for (int r = 1; r <= i; ++r) {
			dp[i + 1][l + 1][r] += dp[i][l][r];
			dp[i + 1][l + 1][r] %= MOD;
			dp[i + 1][l][r + 1] += dp[i][l][r];
			dp[i + 1][l][r + 1] %= MOD;
			dp[i + 1][l][r] += dp[i][l][r] * (i - 1);
			dp[i + 1][l][r] %= MOD;
		}
	}

	cout << dp[n][l][r];
}