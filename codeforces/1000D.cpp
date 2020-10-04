#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n;
int c[1001][1001];
int arr[1001];
int dp[1001];

int choose(int n, int k) {
	if (n < k || n <= 0) return 0;
	if (n == k || k == 0) return 1;
	if (c[n][k] > 0) return c[n][k];
	return c[n][k] = (choose(n - 1, k) + choose(n - 1, k - 1)) % MOD;
}

int get(int i) {
	if (dp[i] != -1) return dp[i];
	if (i >= n) return 0;
	if (arr[i] <= 0) return dp[i] = 0;
	long long ret = choose(n - i - 1, arr[i]);
	for (int j = i + arr[i] + 1; j <= n; ++j) {
		ret += (long long)choose(j - i - 1, arr[i]) * get(j);
		ret %= MOD;
	}
	return dp[i] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	int ans = 0;
	for (int i = 0; i < n; ++i) ans = (ans + get(i)) % MOD;

	cout << ans;
}