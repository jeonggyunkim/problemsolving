#include <iostream>
#define MOD 100000007
using namespace std;

long long dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (2 * (i - 1) + 1) * dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}
	cout << dp[n];
}