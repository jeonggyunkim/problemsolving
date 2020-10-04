#include <iostream>
#include <memory.h>
using namespace std;

int dp[100001];

int ham(int n) {
	int ret;
	if (n <= 100000 && dp[n] != -1) return dp[n];
	if (n % 2 == 1) {
		ret = max(n, ham(3 * n + 1));
		if (n <= 100000) dp[n] = ret;
		return ret;
	}
	else {
		ret = max(n, ham(n / 2));
		if (n <= 100000) dp[n] = ret;
		return ret;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[4] = 4;

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		cout << ham(n) << '\n';
	}
}