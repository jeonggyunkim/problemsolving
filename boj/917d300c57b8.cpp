#include <iostream>
#include <memory.h>
using namespace std;

int dp[101][101][2];

int get(int n, int k, int num) {
	if (n < 1 || k < 0 || k >= n) return 0;
	if (dp[n][k][num] != -1) return dp[n][k][num];
	if (n == k + 1) {
		if (n == 1) return 1;
		if (num == 1) return 1;
		else return 0;
	}
	if (num == 0) {
		return dp[n][k][num] = get(n - 1, k, 0) + get(n - 1, k, 1);
	}
	else {
		return dp[n][k][num] = get(n - 1, k - 1, 1) + get(n - 1, k, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		cout << get(n, k, 0) + get(n, k, 1) << '\n';
	}
}