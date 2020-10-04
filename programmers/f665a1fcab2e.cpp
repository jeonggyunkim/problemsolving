#include <vector>
using namespace std;

int solution(int n) {
	int ans = 0;
	vector<int> dp(n + 1);

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 1000000007;
	}

	return dp[n];
}