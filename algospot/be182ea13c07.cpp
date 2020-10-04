#include <iostream>
using namespace std;

int level(char* a, int n) {
	bool ck = true;
	for (int i = 0; i < n - 1; ++i) if (a[i] != a[i + 1]) ck = false;
	if (ck) return 1;

	ck = true;
	int dif = a[1] - a[0];
	for (int i = 1; i < n - 1; ++i) if (a[i + 1] - a[i] != dif) ck = false;
	if (ck) {
		if (dif == 1 || dif == -1) return 2;
		else return 5;
	}

	ck = true;
	for (int i = 2; i < n; i += 2) if (a[i] != a[0]) ck = false;
	if (n >= 4 && a[1] != a[3]) ck = false;
	if (ck) return 4;

	return 10;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		char c[10001];
		int dp[10001] = {};
		int n = -1;

		cin >> c;
		while (c[++n]);

		n -= 3;
		dp[n] = level(c + n, 3); n--;
		dp[n] = level(c + n, 4); n--;
		dp[n] = level(c + n, 5); n--;
		dp[n] = level(c + n, 3) + dp[n + 3]; n--;
		dp[n] = min(level(c + n, 4) + dp[n + 4], level(c + n, 3) + dp[n + 3]); n--;
		while (n >= 0) {
			dp[n] = min(level(c + n, 3) + dp[n + 3], min(level(c + n, 4) + dp[n + 4], level(c + n, 5) + dp[n + 5]));
			n--;
		}

		cout << dp[0] << '\n';
	}
}
