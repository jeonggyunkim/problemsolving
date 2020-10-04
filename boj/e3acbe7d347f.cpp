#include <iostream>
#include <vector>
using namespace std;

int t[10000];
bool vis[10000];
int dp[10000];

int ans;

vector<vector<int>> edge;

void dfs(int i) {
	vis[i] = 1;
	for (int u: edge[i]) {
		if (!vis[u]) dfs(u);
		dp[i] = max(dp[i], dp[u]);
	}
	dp[i] += t[i];
	ans = max(ans, dp[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	edge.resize(n);
	int a, b;
	while (m--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i);
	}

	cout << ans;
}