#include <iostream>
using namespace std;

int main() {
	int q, n, d;
	cin >> q >> n >> d;

	string s1, s2;
	cin >> s1 >> s2;

	unsigned long long dp[210] = {1, };
	for (int i = 0; i < n; ++i) {
		if (s1[i] != s2[i]) {
			for (int j = 200; j >= 0; --j) {
				dp[j + 2] += dp[j] * (q - 2);
				dp[j + 1] += dp[j] * 2;
				dp[j] = 0;
			}
		}
		else {
			for (int j = 200; j >= 0; --j) {
				dp[j + 2] += dp[j] * (q - 1);
			}
		}
	}
	cout << dp[d];
}