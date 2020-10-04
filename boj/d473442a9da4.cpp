#include <iostream>
#include <queue>
#include <memory.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

char board[55][55];
int dist[50][50][1 << 5];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char cnt = '0';

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) cin >> board[i];

	memset(dist, -1, sizeof(dist));
	queue<iii> q;
	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
		if (board[i][j] == 'S') {
			q.push({i, j, 0});
			dist[i][j][0] = 0;
		}
		if (board[i][j] == 'X') board[i][j] = cnt++;
	}

	int i, j, mask, x, y, now;
	while (!q.empty()) {
		tie(i, j, mask) = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			x = i + loc[k][0];
			y = j + loc[k][1];
			now = mask;
			if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '#') continue;
			if (board[x][y] >= '0' && board[x][y] <= '4') {
				now |= (1 << (board[x][y] - '0'));
			}
			if (dist[x][y][now] == -1) {
				dist[x][y][now] = dist[i][j][mask] + 1;
				q.push({x, y, now});
				if (board[x][y] == 'E' && now == (1 << (cnt - '0')) - 1) {
					cout << dist[x][y][now];
					return 0;
				}
			}
		}
	}
}