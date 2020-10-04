
#include <iostream>
#include <memory.h>
#define N 1000009
using namespace std;

int dp[N];
long long sum[N];

int find(int i) {
	if (dp[i] != -1) return dp[i];
	if (i & 1) return dp[i] = find(i + 1) + 1;
	else return dp[i] = find(i / 2) + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	for (int i = 2; i < N; ++i) find(i);

	for (int i = 1; i < N; ++i) {
		sum[i] = sum[i - 1] + dp[i];
	}

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; ++i) {
		int n1, n2;
		cin >> n1 >> n2;

		cout << "Case #" << i << '\n' << sum[n2] - sum[n1 - 1] << '\n';
	}
}
