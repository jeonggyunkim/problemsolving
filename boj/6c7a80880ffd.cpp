#include <iostream>
#include <memory.h>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char board[1000][1000];
int d[1000][1000][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> board[i];
	memset(d, -1, sizeof(d));

	queue<iii> q;
	d[0][0][0] = 1;
	q.push({0, 0, 0});

	while (!q.empty()) {
		iii now = q.front(); q.pop();
		int x = get<0>(now);
		int y = get<1>(now);
		int z = get<2>(now);
		if (x == n - 1 && y == m - 1) {
			cout << d[x][y][z];
			return 0;
		}
		for (int k = 0; k < 4; ++k) {
			int xx = x + loc[k][0];
			int yy = y + loc[k][1];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if (board[xx][yy] == '0') {
				if (d[xx][yy][z] != -1) continue;
				d[xx][yy][z] = d[x][y][z] + 1;
				q.push({xx, yy, z});
			}
			else {
				if (z == 1) continue;
				else {
					if (d[xx][yy][1] != -1) continue;
					d[xx][yy][1] = d[x][y][z] + 1;
					q.push({xx, yy, 1});
				}
			}
		}
	}
	cout << -1;
}