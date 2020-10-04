#include <iostream>
#include <memory.h>
using namespace std;

int n;
char map[101][101];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[101][101];

void dfs(int i, int j, bool cb) {
	vis[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		int x, y;
		x = i + loc[k][0];
		y = j + loc[k][1];
		if (x < 0 || x >= n || y < 0 || y >= n) continue;
		if (vis[x][y]) continue;
		if (cb) {
			if (map[x][y] == map[i][j] || map[x][y] + map[i][j] == 'R' + 'G') dfs(x, y, cb);
		}
		else if (map[x][y] == map[i][j]) dfs(x, y, cb);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> map[i];

	int ncb = 0, cb = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (!vis[i][j]) {
			dfs(i, j, 0);
			ncb++;
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (!vis[i][j]) {
			dfs(i, j, 1);
			cb++;
		}
	}
	cout << ncb << ' ' << cb;
}