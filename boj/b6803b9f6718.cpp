#include <iostream>
#include <memory.h>
using namespace std;

int dp[1001][2];
int take[3] = {1, 3, 4};

int cal(int n, bool sk) {
	if (dp[n][sk] != -1) return dp[n][sk];
	for (int i = 0; i < 3; ++i) {
		if (n - take[i] >= 0) {
			if (cal(n - take[i], !sk) == sk) return dp[n][sk] = sk;
		}
	}
	return dp[n][sk] = !sk;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0; dp[0][1] = 1;

	if (cal(n, 1) == 1) cout << "SK";
	else cout << "CY";
}