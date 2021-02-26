#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

int n, m;
char board[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INF)));

	queue<i3> q[2];
	ii goal;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'C')	{
				q[0].push({i, j, 0});
				dist[i][j][0] = 0;
			}
			else if (board[i][j] == 'D') goal = {i, j};
		}
	}

	int d = 0;
	while (!q[0].empty() || !q[1].empty()) {
		if (q[d % 2].empty()) {
			d++;
			continue;
		}
		i3 now = q[d % 2].front(); q[d % 2].pop();
		int x, y, dir;
		tie(x, y, dir) = now;
		if (d > dist[x][y][dir]) continue;
		if (dir == 0) {
			if (x == n - 1) continue;
			if (board[x + 1][y] == '#') {
				goto mv;
			}
			else {
				if (d < dist[x + 1][y][0]) {
					q[d % 2].push({x + 1, y, 0});
					dist[x + 1][y][0] = d;
				}
			}
		}
		else {
			if (x == 0) continue;
			if (board[x - 1][y] == '#') {
				goto mv;
			}
			else {
				if (d < dist[x - 1][y][1]) {
					q[d % 2].push({x - 1, y, 1});
					dist[x - 1][y][1] = d;
				}
			}
		}
		continue;

		mv:
		if (y != 0 && board[x][y - 1] != '#') {
			if (d < dist[x][y - 1][dir]) {
				q[d % 2].push({x, y - 1, dir});
				dist[x][y - 1][dir] = d;
			}
		}
		if (y != m - 1 && board[x][y + 1] != '#') {
			if (d < dist[x][y + 1][dir]) {
				q[d % 2].push({x, y + 1, dir});
				dist[x][y + 1][dir] = d;
			}
		}
		if (d + 1 < dist[x][y][1 - dir]) {
			q[(d + 1) % 2].push({x, y, 1 - dir});
			dist[x][y][1 - dir] = d + 1;
		}
	}

	int ans = min(dist[goal.first][goal.second][0], dist[goal.first][goal.second][1]);
	if (ans == INF) cout << -1;
	else cout << ans;
}