#include <bits/stdc++.h>
using namespace std;

int arr[100010][2];
long long dp[100010][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i][0];
	for (int i = 0; i < n; ++i) cin >> arr[i][1];

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = max(dp[i - 1][1] + arr[i - 1][0], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 1][0] + arr[i - 1][1], dp[i - 1][1]);
	}

	cout << max(dp[n][0], dp[n][1]);
}