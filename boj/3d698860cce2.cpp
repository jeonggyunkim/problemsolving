#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<vector<int>> edge;

int dp[1000000][2];

int ans(int n, int color, int p) {
	if (dp[n][color] != -1) return dp[n][color];
	int ret = 0;
	if (color == 0) {
		for (int u : edge[n]) {
			if (u != p) {
				ret += ans(u, 1, n);
			}
		}
		return dp[n][color] = ret;
	}
	else {
		ret++;
		for (int u : edge[n]) {
			if (u != p) {
				ret += min(ans(u, 0, n), ans(u, 1, n));
			}
		}
		return dp[n][color] = ret;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	edge.resize(n);

	memset(dp, -1, sizeof(dp));

	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	cout << min(ans(0, 0, -1), ans(0, 1, -1));
}