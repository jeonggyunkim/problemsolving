#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> vis;

void dfs(int n) {
	vis[n] = 1;
	for (int u : edge[n]) {
		if (!vis[u]) dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	edge.resize(v);
	vis.resize(v, 0);
	vector<int> cnt(v);
	int a, b;
	while (e--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
	}

	dfs(0);
	for (int i = 1; i < v; ++i) if (!vis[i]) {
		cout << "NO";
		return 0;
	}

	int odd = 0;
	for (int i = 0; i < v; ++i) {
		if (cnt[i] & 1) odd++;
	}

	if (odd == 0 || odd == 2) cout << "YES";
	else cout << "NO";
}