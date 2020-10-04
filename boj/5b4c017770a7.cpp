#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;

char board[21][21];
int dist[20][20][20][20];

int loc[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	int n, m;
	cin >> n >> m;

	i4 now = {{-1, -1}, {-1, -1}};
	for (int i = 0; i < n; ++i) cin >> board[i];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (board[i][j] == 'o') {
			if (now.first.first == -1) now.first = {i, j};
			else now.second = {i, j};
		}
	}

	queue<i4> q;
	q.push(now);
	dist[now.first.first][now.first.second][now.second.first][now.second.second] = 0;

	while (!q.empty()) {
		now = q.front();
		q.pop();
		int d = dist[now.first.first][now.first.second][now.second.first][now.second.second];

		for (int k = 0; k < 4; ++k) {
			ii one = now.first;
			ii two = now.second;
			int x, y;
			int drop = 0;

			x = one.first + loc[k][0];
			y = one.second + loc[k][1];
			if (x < 0 || x >= n || y < 0 || y >= m) drop++;
			else {
				if (board[x][y] != '#') one = {x, y};
			}
			
			x = two.first + loc[k][0];
			y = two.second + loc[k][1];
			if (x < 0 || x >= n || y < 0 || y >= m) drop++;
			else {
				if (board[x][y] != '#') two = {x, y};
			}

			if (drop == 1) {
				cout << d + 1;
				return 0;
			}
			else if (drop == 0 && one != two) {
				if (two > one) swap(one, two);
				if (dist[one.first][one.second][two.first][two.second] == -1) {
					dist[one.first][one.second][two.first][two.second] = d + 1;
					q.push({one, two});
				}
			}
		}
	}
	cout << -1;
}