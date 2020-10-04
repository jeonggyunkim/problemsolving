#include <iostream>
using namespace std;

int dp[256][256];
int mini[256][256];

int find(int s, int f) {
	if (s == f) return 0;
	if (dp[s][f] > 0) return dp[s][f];
	int ret = 987654321;
	for (int i = s; i < f; ++i) {
		int r = find(s, i) + find(i + 1, f) + abs(mini[s][i] - mini[i + 1][f]);
		ret = min(ret, r);
	}
	return dp[s][f] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, arr[256];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	for (int i = 0; i < n; ++i) {
		int m = 9876;
		for (int j = i; j < n; ++j) {
			m = min(m, arr[j]);
			mini[i][j] = m;
		}
	}

	cout << find(0, n - 1);
}