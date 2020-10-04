#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(50001, 10);

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; i - j * j >= 0; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];
}