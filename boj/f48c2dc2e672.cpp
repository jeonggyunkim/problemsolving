#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char adj[101][101];
vector<vector<int>> edge;
int vis[101];

bool dfs(int i) {
	vis[i] = 1;
	for (int u: edge[i]) {
		if (vis[u] == 1) return 0;
		else if (vis[u] == 0 && !dfs(u)) return 0;
	}
	vis[i] = 2;
	return 1;
}

int main() {
	int n;
	cin >> n;
	edge.resize(n);

	for (int i = 0; i < n; ++i) cin >> adj[i];

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (adj[i][j] != adj[j][i]) {
				if (adj[i][j] == 'Y') edge[i].push_back(j);
				else edge[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0 && !dfs(i)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}