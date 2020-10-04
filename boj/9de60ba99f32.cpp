#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char arr[55][55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		cin >> arr[i];
	}

	queue<ii> q, water;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 'S') {
				q.push({i, j});
				arr[i][j] = '.';
			}
			if (arr[i][j] == '*') water.push({i, j});
		}
	}

	int d = 1;
	while (1) {
		queue<ii> next, watert;
		bool vis[55][55] = {};
		while (!q.empty()) {
			ii now = q.front(); q.pop();
			if (arr[now.first][now.second] == '*') continue;
			for (int k = 0; k < 4; ++k) {
				int x = now.first + loc[k][0];
				int y = now.second + loc[k][1];
				if (x < 0 || x >= r || y < 0 || y >= c) continue;
				if (arr[x][y] == 'D') {
					cout << d;
					return 0;
				}
				if (!vis[x][y] && arr[x][y] == '.') {
					next.push({x, y});
					vis[x][y] = 1;
				}
			}
		}

		if (next.empty()) {
			cout << "KAKTUS";
			return 0;
		}
		memset(vis, 0, sizeof(vis));

		while (!water.empty()) {
			ii now = water.front(); water.pop();
			for (int k = 0; k < 4; ++k) {
				int x = now.first + loc[k][0];
				int y = now.second + loc[k][1];
				if (x < 0 || x >= r || y < 0 || y >= c) continue;
				if (!vis[x][y] && arr[x][y] == '.') {
					watert.push({x, y});
					arr[x][y] = '*';
					vis[x][y] = 1;
				}
			}
		}

		q = next;
		water = watert;
		d++;
	}
}