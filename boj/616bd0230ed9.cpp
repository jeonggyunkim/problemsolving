#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<int> dp;

int get(int n) {
	if (dp[n] > 0) return dp[n];
	int ret = 1;
	for (int u: edge[n]) {
		ret = max(ret, get(u) + 1);
	}
	return dp[n] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	edge.resize(n);
	dp.resize(n, 0);

	int a, b;
	while (m--) {
		cin >> a >> b;
		a--; b--;
		edge[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) cout << get(i) << ' ';
}