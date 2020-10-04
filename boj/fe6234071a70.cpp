#include <iostream>
#include <memory.h>
#define MOD 1000000009
using namespace std;

int dp[1001][1001];

int cal(int n, int m) {
	if (n == m) return 1;
	if (n < 0 || m == 0) return 0;
	if (dp[n][m] != -1) return dp[n][m];
	return dp[n][m] = ((cal(n - 1, m - 1) + cal(n - 2, m - 1)) % MOD + cal(n - 3, m - 1)) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;

		cout << cal(n, m) << '\n';
	}
}