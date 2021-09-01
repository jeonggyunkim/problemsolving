#include <iostream>
#include <memory.h>
#define MOD 10007
using namespace std;

int dp[53][53];

int choose(int n, int c) {
	if (n == 0 || c == 0 || n == c) return 1;
	if (dp[n][c] != -1) return dp[n][c];

	return dp[n][c] = (choose(n - 1, c) + choose(n - 1, c - 1)) % MOD;
}

int main() {
	memset(dp, -1, sizeof(dp));

	int n;
	cin >> n;

	int ans = 0, now;
	for (int i = 1; i < (1 << 13); ++i) {
		int cnt = __builtin_popcount(i);
		if (n < cnt * 4) now = 0;
		else {
			now = choose(52 - 4 * cnt, n - 4 * cnt);
		}
		if (cnt & 1) ans += now;
		else ans -= now;
	}
	while (ans < 0) ans += MOD;
	ans %= MOD;
	cout << ans;
}