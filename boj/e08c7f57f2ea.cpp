#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> visit;
vector<bool> cut;
int counter = 0;

int dfs(int i, bool root = false) {
	visit[i] = counter++;

	int ret = INF;
	int cnt = 0;
	for (int u: adj[i]) {
		if (visit[u] == -1) {
			cnt++;
			int r = dfs(u);
			if (!root && r >= visit[i]) cut[i] = 1;
			ret = min(ret, r);
		}
		else {
			ret = min(ret, visit[u]);
		}
	}

	if (root && cnt > 1) cut[i] = 1;

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;

	adj.resize(n + 1);
	visit.resize(n + 1, -1);
	cut.resize(n + 1, 0);

	int a, b;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) if (visit[i] == -1) dfs(i, 1);

	int ans = 0;
	for (int i = 1; i <= n; ++i) if (cut[i]) ans++;

	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		if (cut[i]) cout << i << ' ';
	}
}