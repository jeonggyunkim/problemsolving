#include <iostream>
using namespace std;

long long dp[11][221];

int main() {
	for (int i = 0; i <= 220; ++i) dp[1][i] = 1;

	for (int i = 2; i <= 10; ++i) {
		for (int j = 0; j <= 220; ++j) {
			for (int k = 0; j - i * k >= 0; ++k) {
				dp[i][j] += dp[i - 1][j - i * k];
			}
		}
	}

	int n, m;
	long long k;
	cin >> n >> m >> k;

	int now = 1;
	m -= n;
	while (n > 1) {
		while (1) {
			if (dp[n - 1][m] >= k) break;
			else {
				now++;
				k -= dp[n - 1][m];
				m -= n;
			}
		}
		cout << now << ' ';
		n--;
	}
	cout << now + m;
}