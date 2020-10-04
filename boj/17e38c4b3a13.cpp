#include <iostream>
#include <memory.h>
using namespace std;

bool vis[101][101];
int board[101][101];
int n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, int d) {
	vis[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		int x = i + dir[k][0];
		int y = j + dir[k][1];
		if (x < 0 || x >= n || y < 0 || y >= n) continue;
		if (!vis[x][y]) dfs(x, y, d);
	}
}

int main() {
	cin >> n;
	int minv = 101, maxv = -1;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> board[i][j];
		minv = min(minv, board[i][j]);
		maxv = max(maxv, board[i][j]);
	}

	int ans = 1;
	for (int d = minv; d <= maxv; ++d) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (board[i][j] <= d) vis[i][j] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			if (!vis[i][j]) {
				dfs(i, j, d);
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}