#include <iostream>
using namespace std;

double dp[7][7][7][1010];
double sc[7][7][7];

int score(int a, int b, int c) {
	if (a == b && b == c) return 10000 + 1000 * a;
	if (a == b || b == c || c == a) {
		if (a == b) return 1000 + 100 * a;
		if (b == c) return 1000 + 100 * b;
		if (c == a) return 1000 + 100 * c;
	}
	if (b < c) swap(b, c);
	if (a < b) swap(a, b);
	return 100 * a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= 6; ++j) {
			for (int k = 1; k <= 6; ++k) {
				sc[i][j][k] = score(i, j, k);
				dp[i][j][k][0] = sc[i][j][k];
			}
		}
	}

	for (int rep = 1; rep < 1000; ++rep) {
		for (int i = 1; i <= 6; ++i) {
			for (int j = 1; j <= 6; ++j) {
				for (int k = 1; k <= 6; ++k) {
					double now = 0;
					for (int l = 1; l <= 6; ++l) {
						now += dp[j][k][l][rep - 1];
					}
					now /= 6;
					dp[i][j][k][rep] = max(sc[i][j][k], now);
				}
			}
		}
	}

	double ans = 0;
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= 6; ++j) {
			for (int k = 1; k <= 6; ++k) {
				ans += dp[i][j][k][n - 3];
			}
		}
	}
	cout.precision(30);
	cout << ans / 216;
}