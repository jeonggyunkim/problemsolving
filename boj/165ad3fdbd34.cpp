#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

char arr[17][17];
int dp[15][1 << 15];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) arr[i][j] -= '0';
	}

	priority_queue<iii, vector<iii>, greater<iii>> pq;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n); ++j) dp[i][j] = 10;
	}

	dp[0][1] = 0;
	pq.push({0, 0, 1});
	int d, u, mask;
	while (!pq.empty()) {
		tie(d, u, mask) = pq.top(); pq.pop();
		if (d > dp[u][mask]) continue;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) continue;
			int nextmask = mask | (1 << i);
			if (arr[u][i] >= dp[u][mask] && arr[u][i] < dp[i][nextmask]) {
				dp[i][nextmask] = arr[u][i];
				pq.push({arr[u][i], i, nextmask});
			}
		}
	}

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			if (dp[i][j] != 10) ans = max(ans, __builtin_popcount(j));
		}
	}
	cout << ans;
}