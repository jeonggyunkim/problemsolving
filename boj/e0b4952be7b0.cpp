#include <iostream>
#include <memory.h>
using namespace std;

int m, n;
char map[101][101];
bool vis[101][101];

void dfs(int x, int y) {
	if (x < 0 || x >= m || y < 0 || y >= n) return;
	if (map[x][y] == '*' || vis[x][y]) return;
	vis[x][y] = 1;
	for (int i = -1; i <= 1; ++i) for (int j = -1; j <= 1; ++j) dfs(x + i, y + j);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> m >> n, m) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; ++i) cin >> map[i];

		int cnt = 0;
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
			if (map[i][j] == '@' && !vis[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}

		cout << cnt << '\n';
	}
}