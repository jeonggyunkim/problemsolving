#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> edge;
vector<int> topo;

void dfs(int n) {
	visited[n] = 1;
	for (int u: edge[n]) {
		if (visited[u] != 1) dfs(u);
	}
}

void topolo(int n) {
	visited[n] = 2;
	for (int u: edge[n]) {
		if (visited[u] == 0) topolo(u);
	}
	topo.push_back(n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;

	visited.resize(n + 1, 0);
	edge.resize(n + 1);

	int a, b;
	while (m--) {
		cin >> a >> b;
		edge[a].push_back(b);
	}

	dfs(s);
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 0) topolo(i);
	}

	int ans = 0;

	for (int i = topo.size() - 1; i >= 0; --i) {
		if (visited[topo[i]] != 1) {
			ans++;
			dfs(topo[i]);
		}
	}
	cout << ans;
}