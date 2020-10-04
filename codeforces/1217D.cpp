#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> edge;
int vis[5010];

bool dfs(int i) {
	vis[i] = 1;
	for (int u: edge[i]) {
		if (vis[u] == 1) return 1;
		else if (vis[u] == 0 && dfs(u)) return 1;
	}
	vis[i] = 2;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	edge.resize(n);
	vector<ii> e(m);
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		e[i] = {a, b};
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i] && dfs(i)) {
			cout << "2\n";
			for (int i = 0; i < m; ++i) {
				if (e[i].first > e[i].second) cout << "2 ";
				else cout << "1 ";
			}
			return 0;
		}
	}

	cout << "1\n";
	while (m--) cout << "1 ";
}