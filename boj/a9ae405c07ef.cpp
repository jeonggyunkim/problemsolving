#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[30];
bool vis[30];
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

	int n, t;
	cin >> n;
	edge.resize(2 * n - 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			if (t == 1) edge[i + j].push_back(i - j + n);
		}
	}

	int size = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < 2 * n - 1; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) size++;
	}

	cout << size;
}