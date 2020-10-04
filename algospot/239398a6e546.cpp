#include <iostream>
#include <memory.h>
using namespace std;

int n, m;
int dp[101][101];
long long a[101];
long long b[101];

int jlis(int i, int j) {
	if (dp[i][j] > 0) return dp[i][j];
	long long large = a[i] > b[j] ? a[i] : b[j];
	int max = 1, t;
	for (int k = i + 1; k <= n; ++k) {
		if (a[k] > large) {
			t = jlis(k, j);
			if (t > max) max = t;
		}
	}
	for (int k = j + 1; k <= m; ++k) {
		if (b[k] > large) {
			t = jlis(i, k);
			if (t > max) max = t;
		}
	}

	return dp[i][j] = max + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	a[0] = (1LL << 63);
	b[0] = (1LL << 63) + 1;

	while (tc--) {
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= m; ++i) cin >> b[i];

		cout << jlis(0, 0) - 2 << '\n';
	}
}
