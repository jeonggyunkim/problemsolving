#include <iostream>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

typedef tuple<int, int, int> iii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int map[50][50];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> map[i][j];
	if (map[0][0] >= 14) {
		cout << "BAD";
		return 0;
	}

	queue<iii> q;
	q.push(iii(0, 0, 0));

	int d[50][50][3];
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 3; ++k) {
		d[i][j][k] = INF;
	}
	d[0][0][0] = 0;

	while (!q.empty()) {
		iii u = q.front();
		q.pop();
		int i = get<0>(u) / 100;
		int j = get<0>(u) % 100;
		int type = get<1>(u);
		int com = get<2>(u);
		for (int k = 0; k < 4; ++k) {
			int x = i + loc[k][0];
			int y = j + loc[k][1];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (type == 0) {
				if (map[x][y] >= 14) {
					if (d[x][y][1] > com + 1) {
						d[x][y][1] = com + 1;
						q.push(iii(x * 100 + y, 1, com + 1));
					}
				}
			}
			else if (type == 1) {
				if (map[x][y] < 14) {
					if (d[x][y][0] > com) {
						d[x][y][0] = com;
						q.push(iii(x * 100 + y, 0, com));
					}
					if (d[x][y][2] > com) {
						d[x][y][2] = com;
						q.push(iii(x * 100 + y, 2, com));
					}
				}
			}
			else {
				if (map[x][y] < 14) {
					if (d[x][y][0] > com) {
						d[x][y][0] = com;
						q.push(iii(x * 100 + y, 0, com));
					}
				}
			}
		}
	}
	if (d[n - 1][m - 1][1] == INF && d[n - 1][m - 1][2] == INF) cout << "BAD";
	else cout << min(d[n - 1][m - 1][1], d[n - 1][m - 1][2]);
}