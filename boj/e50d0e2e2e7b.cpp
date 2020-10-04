#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int bm[3205];
bool vis[3205];
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

	int c, m, n;
	cin >> c;

	while (c--) {
		cin >> m >> n;

		char input[82][82];
		int num[82][82];
		for (int i = 0; i < m; ++i) cin >> input[i];

		int a = 0, b = 0;
		for (int i = 1; i < n; i += 2) {
			for (int j = 0; j < m; ++j) {
				if (input[j][i] == '.') num[j][i] = b++;
			}
		}

		edge.clear();

		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < m; ++j) {
				if (input[j][i] == '.') {
					num[j][i] = a;
					edge.push_back(vector<int>());
					for (int xi: {-1, 1}) {
						for (int yi = -1; yi <= 1; ++yi) {
							if (xi == 0 && yi == 0) continue;
							int x = i + xi, y = j + yi;
							if (x >= 0 && x < n && y >= 0 && y < m && input[y][x] == '.') {
								edge[a].push_back(num[y][x]);
							}
						}
					}
					a++;
				}
			}
		}

		int size = 0;
		memset(bm, -1, sizeof(bm));
		for (int i = 0; i < a; ++i) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i)) size++;
		}

		cout << a + b - size << '\n';
	}
}