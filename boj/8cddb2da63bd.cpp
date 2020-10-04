#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int dp[10001][2];
bool used[10001][2];
int w[10001], p[10001];
vector<vector<int>> edge;
vector<int> ans;

void dfs(int n) {
	for (int u: edge[n]) {
		if (u != p[n]) {
			p[u] = n;
			dfs(u);
		}
	}
}

int ts(int n, bool canuse) {
	if (dp[n][canuse] != -1) return dp[n][canuse];
	int ret = 0;
	if (canuse) {
		int r = w[n];
		for (int u: edge[n]) if (u != p[n]) r += ts(u, 0);
		ret = r;
		used[n][canuse] = 1;
	}
	int r = 0;
	for (int u: edge[n]) if (u != p[n]) r += ts(u, 1);
	if (r > ret) {
		ret = r;
		used[n][canuse] = 0;
	}
	return dp[n][canuse] = ret;
}

void dfs_ans(int n, bool canuse) {
	if (used[n][canuse]) ans.push_back(n);
	for (int u: edge[n]) {
		if (u != p[n]) {
			if (used[n][canuse]) dfs_ans(u, 0);
			else {
				if (dp[u][0] > dp[u][1]) dfs_ans(u, 0);
				else dfs_ans(u, 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> w[i];

	int a, b;
	edge.resize(n + 1);
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1);
	memset(dp, -1, sizeof(dp));

	int t1 = ts(1, 0);
	int t2 = ts(1, 1);

	if (t1 > t2) dfs_ans(1, 0);
	else dfs_ans(1, 1);

	sort(ans.begin(), ans.end());

	cout << max(t1, t2) << '\n';
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}