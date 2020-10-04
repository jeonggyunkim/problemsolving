#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int pow2(int i) {
	long long b = 2;
	long long ret = 1;
	while (i != 0) {
		if (i & 1) ret = (ret * b) % MOD;
		b = (b * b) % MOD;
		i >>= 1;
	}
	return ret;
}

int arr[1 << 20];
int dp[1 << 20][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[arr[i]][0]++;
	}

	for (int k = 0; k < 20; ++k) {
		for (int i = 0; i < (1 << 20); ++i) {
			if (i & (1 << k)) {
				dp[i][k + 1] = dp[i][k];
			}
			else {
				dp[i][k + 1] = (dp[i][k] + dp[i + (1 << k)][k]) % MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << 20); ++i) {
		if (__builtin_popcount(i) & 1) {
			ans -= pow2(dp[i][20]);
			if (ans < 0) ans += MOD;
		}
		else {
			ans += pow2(dp[i][20]);
			ans %= MOD;
		}
	}
	cout << ans;
}