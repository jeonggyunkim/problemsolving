#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int n;
int arr[101];
int dp[101][11];

int find_min(int a, int b) {
	int sum = 0;
	for (int i = a; i < b; ++i) {
		sum += arr[i];
	}
	sum += (b - a) / 2;
	sum /= b - a;

	int sq = 0;
	for (int i = a; i < b; ++i) {
		sq += (sum - arr[i]) * (sum - arr[i]);
	}

	return sq;
}

int rec(int sp, int s) {
	if (dp[sp][s] != -1) return dp[sp][s];
	if (s == 1) return dp[sp][s] = find_min(sp, n);
	if (sp == n - 1) return dp[sp][s] = 0;
	int min = (1 << 30);
	for (int i = sp + 1; i < n; ++i) {
		int t = find_min(sp, i) + rec(i, s - 1);
		if (min > t) min = t;
	}
	return dp[sp][s] = min;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int s;
		cin >> n >> s;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr, arr + n);

		cout << rec(0, s) << '\n';
	}
}
