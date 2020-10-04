#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int cnt;

int dfs(int n) {
	visited[n] = 1;

	int child[3] = {};
	for (int u: edge[n]) {
		if (!visited[u]) child[dfs(u)]++;
	}

	if (child[0]) {
		cnt++;
		return 2;
	}
	if (child[2]) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int g, h;
		cin >> g >> h;
		edge.clear(); edge.resize(g);
		visited.clear(); visited.resize(g, 0);
		cnt = 0;

		int a, b;
		while (h--) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		for (int i = 0; i < g; ++i) {
			if (visited[i] == 0) {
				if (dfs(i) == 0) cnt++;
			}
		}

		cout << cnt << '\n';
	}
}
