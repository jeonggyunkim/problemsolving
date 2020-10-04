#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[110];
bool vis[110];
vector<vector<int>> edge;

bool dfs(int a) {
	if (vis[a]) return 0;
	vis[a] = 1;

	for (int b: edge[a]) {
		if (bm[b] == -1 || dfs(bm[b])) {
			bm[b] = a;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	edge.resize(n);

	int a, b;
	while (m--) {
		cin >> a >> b;
		edge[a - 1].push_back(b - 1);
	}

	int size = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) size++;
	}

	cout << size;
}