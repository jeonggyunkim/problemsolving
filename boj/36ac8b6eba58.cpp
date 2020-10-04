#include <iostream>
#include <memory.h>
using namespace std;

long long dp[1010][1010];
int ball[1010][1010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while (cin >> n, n) {
		memset(dp, 0, sizeof(dp));

		long long sum = 0;

		for (int s = n - 1; s >= 0; --s) {
			for (int i = 0, j = s; j < n; ++i, ++j) {
				cin >> ball[i][j];
				sum += ball[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) ball[i][j] += ball[i][j - 1];
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + ball[i - 1][j - 1]);
			}
		}

		cout << sum - dp[n][n] << '\n';
	}
}