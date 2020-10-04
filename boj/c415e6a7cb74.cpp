#include <iostream>
#define L 250010
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, h;
	cin >> n;

	int dp[L] = {};

	for (int i = 0; i < n; ++i) {
		cin >> h;
		int temp[L] = {};
		for (int j = 0; j < L; ++j) {
			if (dp[j] > 0) {
				if (h < j) temp[j - h] = max(temp[j - h], dp[j]);
				else if (h - j < L) temp[h - j] = max(temp[h - j], dp[j] - j + h);
				temp[j] = max(temp[j], dp[j]);
				if (j + h < L) temp[j + h] = max(temp[j + h], dp[j] + h);
			}
		}
		if (h < L) temp[h] = max(temp[h], h);
		for (int j = 0; j < L; ++j) dp[j] = temp[j];
	}
	if (dp[0] == 0) cout << -1;
	else cout << dp[0];
}