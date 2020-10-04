#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char board[51][51];
int d[51][51][1 << 6];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(d, -1, sizeof(d));

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> board[i];

	queue<ii> q;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (board[i][j] == '0') {
			q.push({i * 100 + j, 0});
			d[i][j][0] = 0;
		}
	}

	while (!q.empty()) {
		ii now = q.front(); q.pop();
		int i = now.first / 100, j = now.first % 100;
		int mask = now.second;
		for (int k = 0; k < 4; ++k) {
			int x = i + loc[k][0], y = j + loc[k][1];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (board[x][y] == '#') continue;
			else if (board[x][y] >= 'a' && board[x][y] <= 'f') {
				int nowmask = mask | (1 << (board[x][y] - 'a'));
				if (d[x][y][nowmask] == -1) {
					d[x][y][nowmask] = d[i][j][mask] + 1;
					q.push({x * 100 + y, nowmask});
				}
			}
			else if (board[x][y] >= 'A' && board[x][y] <= 'F') {
				if (mask & (1 << (board[x][y] - 'A'))) {
					if (d[x][y][mask] == -1) {
						d[x][y][mask] = d[i][j][mask] + 1;
						q.push({x * 100 + y, mask});
					}
				}
			}
			else if (board[x][y] == '1') {
				cout << d[i][j][mask] + 1;
				return 0;
			}
			else {
				if (d[x][y][mask] == -1) {
					d[x][y][mask] = d[i][j][mask] + 1;
					q.push({x * 100 + y, mask});
				}
			}
		}
	}
	cout << -1;
}