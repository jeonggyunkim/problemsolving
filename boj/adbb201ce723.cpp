#include <iostream>
using namespace std;

typedef pair<int, int> ii;

int dp[501][501] = {};
ii size[501];

int cal(int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] > 0) return dp[i][j];
	if (j - i == 1) return dp[i][j] = size[i].first * size[i].second * size[j].second;
	int min = ~(1 << 31);
	for (int k = i; k < j; ++k) {
		int t = cal(i, k) + cal(k + 1, j) + size[i].first * size[k].second * size[j].second;
		if (t < min) min = t;
	}
	return dp[i][j] = min;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> size[i].first >> size[i].second;

	cout << cal(0, n - 1);
}