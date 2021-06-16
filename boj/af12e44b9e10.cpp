#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int n, m;
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char board[701][701];
int pirate_first_see[701][701][2];
int pirate_vis[701][701];
int vis[701][701];

void look(int x, int y, int t) {
	if (pirate_first_see[x][y][0] == 0) {
		pirate_first_see[x][y][0] = t;
		for (int i = y - 1; i >= 0; --i) {
			if (board[x][i] != 'I') {
				pirate_first_see[x][i][0] = t;
			}
			else break;
		}
		for (int i = y + 1; i < m; ++i) {
			if (board[x][i] != 'I') {
				pirate_first_see[x][i][0] = t;
			}
			else break;
		}
	}
	if (pirate_first_see[x][y][1] == 0) {
		pirate_first_see[x][y][1] = t;
		for (int i = x - 1; i >= 0; --i) {
			if (board[i][y] != 'I') {
				pirate_first_see[i][y][1] = t;
			}
			else break;
		}
		for (int i = x + 1; i < n; ++i) {
			if (board[i][y] != 'I') {
				pirate_first_see[i][y][1] = t;
			}
			else break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(pirate_vis, -1, sizeof(pirate_vis));
	memset(vis, -1, sizeof(vis));

	cin >> n >> m;

	ii y, v, t;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'Y') y = {i, j};
			if (board[i][j] == 'V') v = {i, j};
			if (board[i][j] == 'T') t = {i, j};
		}
	}

	queue<ii> q;
	q.push(v);
	pirate_vis[v.first][v.second] = 0;

	while (!q.empty()) {
		ii now = q.front(); q.pop();
		if (pirate_vis[now.first][now.second]) look(now.first, now.second, pirate_vis[now.first][now.second]);
		for (int k = 0; k < 4; ++k) {
			int x = now.first + loc[k][0];
			int y = now.second + loc[k][1];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (pirate_vis[x][y] == -1 && board[x][y]!= 'I') {
				pirate_vis[x][y] = pirate_vis[now.first][now.second] + 1;
				q.push({x, y});
			}
		}
	}

	q.push(y);
	vis[y.first][y.second] = 0;
	while (!q.empty()) {
		ii now = q.front(); q.pop();
		int d = vis[now.first][now.second] + 1;
		for (int k = 0; k < 4; ++k) {
			int x = now.first + loc[k][0];
			int y = now.second + loc[k][1];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (vis[x][y] == -1 && board[x][y] != 'I' && min(pirate_first_see[x][y][0], pirate_first_see[x][y][1]) > d) {
				vis[x][y] = d;
				q.push({x, y});
			}
		}
	}

	if (vis[t.first][t.second] == -1) cout << "NO";
	else cout << "YES";
}