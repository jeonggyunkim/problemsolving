#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

long long dp[1 << 15][100];
string arr[15];
int pow10[800] = {1};
int rem[15];
int n, k;

long long gcd(long long a, long long b) {
	long long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

void get(int mask) {
	for (int i = 0; i < k; ++i) dp[mask][i] = 0;
	int len = 0;
	for (int i = 0; i < n; ++i) if (mask & (1 << i)) len += arr[i].size();

	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			len -= arr[i].size();
			int r = pow10[len] * rem[i];

			int mask2 = mask & ~(1 << i);
			if (dp[mask2][0] == -1) get(mask2);
			for (int j = 0; j < k; ++j) {
				dp[mask][(r + j) % k] += dp[mask2][j];
			}

			len += arr[i].size();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cin >> k;

	if (k == 1) {
		cout << 1 << '/' << 1;
		return 0;
	}

	for (int i = 1; i < 800; ++i) pow10[i] = (pow10[i - 1] * 10) % k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < arr[i].length(); ++j) {
			rem[i] *= 10;
			rem[i] = (rem[i] + arr[i][j] - '0') % k;
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i < k; ++i) dp[0][i] = 0;

	get((1 << n) - 1);
	long long ans = dp[(1 << n) - 1][0];
	long long fac = 1;
	for (int i = 1; i <= n; ++i) fac *= i;
	long long t = gcd(fac, ans);

	cout << ans / t << '/' << fac / t;
}