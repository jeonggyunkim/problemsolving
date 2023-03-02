#include <iostream>
#include <vector>
using namespace std;

int ans, vis[500];
vector<vector<int>> edge;

void dfs(int i) {
	ans++;
	vis[i] = 1;
	for (int u: edge[i]) {
		if (!vis[u]) {
			dfs(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	edge.resize(n);

	while (m--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(0);
	cout << ans;
}