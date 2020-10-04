#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
bool vis[300000];

void dfs(int i, int p) {
	vis[i] = 1;
	for (int u: edge[i]) {
		if (u != p) dfs(u, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	edge.resize(n);
	int a, b;
	for (int i = 0; i < n - 2; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(0, -1);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			cout << i + 1 << ' ' << 1;
			return 0;
		}
	}
}