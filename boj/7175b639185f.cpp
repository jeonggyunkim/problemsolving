#include <iostream>
using namespace std;

double dp[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		double ret = 0;
		for (int j = 1; j <= 6; ++j) {
			if (i - j >= 1) ret += dp[i - j];
			ret += 1;
		}
		dp[i] = ret / 6;
	}

	cout.precision(20);
	cout << dp[n];
}