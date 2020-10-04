#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[1010];
bool vis[1010];
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
	for (int i = 0; i < n; ++i) {
		cin >> a;
		while (a--) {
			cin >> b;
			edge[i].push_back(--b);
		}
	}

	int size = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) size++;
	}

	cout << size;
}