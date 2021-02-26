#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[310];
bool vis[310];
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

	int n, m, k1, k2;
	cin >> n >> m >> k1 >> k2;

	edge.resize(n);

	int a, b;
	while (k1--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
	}

	int s1 = 0, s2 = 0;
	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) s1++;
	}

	edge.clear();
	edge.resize(n);

	while (k2--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
	}

	memset(bm, -1, sizeof(bm));
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) s2++;
	}


	if (s1 < s2) cout << "네 다음 힐딱이";
	else cout << "그만 알아보자";
}