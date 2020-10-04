#include <iostream>
using namespace std;

unsigned int dp[32][32];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 32; ++i) for (int j = 0; j < 32; ++j) {
		if (i == 0 || j == 0) dp[i][j] = 1;
		else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}

	unsigned int n, l, i;
	cin >> n >> l >> i;

	while (n) {
		if (dp[n - 1][l] >= i) cout << 0;
		else {
			cout << 1;
			i -= dp[n - 1][l];
			l--;
		}
		n--;
	}
}