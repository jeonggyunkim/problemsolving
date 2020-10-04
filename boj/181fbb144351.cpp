#include <iostream>
#include <memory.h>
using namespace std;

int dp[200][1 << 14];
int n, m;

int cal(int pos, int mask) {
	if (dp[pos][mask] != -1) return dp[pos][mask];
	int ret = 0;
	int i = pos % m, j = pos / m;
	if (i != m - 1 && !(mask & 2)) {
		int mask2 = (mask | 3);
		ret += cal(pos + __builtin_ctz(~mask2), mask2 >> __builtin_ctz(~mask2));
	}
	if (j != n - 1) {
		int mask2 = (mask | 1);
		mask2 |= (1 << m);
		ret += cal(pos + __builtin_ctz(~mask2), mask2 >> __builtin_ctz(~mask2));
	}
	return dp[pos][mask] = ret % 9901;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m;

	if ((n * m) % 2 == 1) {
		cout << 0;
		return 0;
	}

	dp[n * m][0] = 1;
	cout << cal(0, 0);
}