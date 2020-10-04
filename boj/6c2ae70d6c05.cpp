#include <iostream>
using namespace std;

int n;
int dist[16][16];
int dp[16][1 << 16];

int travel(int last, int mask) {
	if (dp[last][mask] > 0) return dp[last][mask];
	if (mask == (1 << n) - 1) {
		if (dist[last][0] == 0) return 1 << 29;
		else return dp[last][mask] = dist[last][0];
	}
	int ret = 1 << 29;
	for (int i = 0; i < n; ++i) {
		if ((mask & (1 << i)) == 0 && dist[last][i] != 0) {
			int t = dist[last][i] + travel(i, mask | (1 << i));
			ret = min(ret, t);
		}
	}
	return dp[last][mask] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> dist[i][j];

	travel(0, 1);
	cout << dp[0][1];
}