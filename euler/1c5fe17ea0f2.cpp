#include <iostream>
using namespace std;

int dp[1000010];

int collatz(long long i) {
	if (i <= 1000000 && dp[i] > 0) return dp[i];
	if (i == 1) return dp[i] = 1;
	int ret;
	if (i & 1) ret = collatz(3 * i + 1) + 1;
	else return ret = collatz(i / 2) + 1;
	if (i <= 1000000) dp[i] = ret;
	return ret;
}

int main() {
	int big = -1, ans;
	for (int i = 1; i <= 1000000; ++i) {
		int now = collatz(i);
		if (now > big) {
			big = now;
			ans = i;
		}
	}
	cout << ans << endl;
}