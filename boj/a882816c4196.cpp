#include <iostream>
#include <memory.h>
using namespace std;

int mem[100], c[100];
int dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> mem[i];
	for (int i = 0; i < n; ++i) cin >> c[i];

	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 10000; j >= 0; --j) {
			if (dp[j] != -1) {
				dp[j + c[i]] = max(dp[j + c[i]], dp[j] + mem[i]);
			}
		}
	}
	for (int i = 0; i <= 10000; ++i) {
		if (dp[i] >= m) {
			cout << i;
			return 0;
		}
	}
}