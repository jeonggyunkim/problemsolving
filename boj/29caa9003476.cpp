#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> i4;

char board[11][11];
int dist[10][10][10][10];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> board[i];

	ii r, b, o, rr, bb;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'R') {
				r = {i, j};
				board[i][j] = '.';
			}
			if (board[i][j] == 'B') {
				b = {i, j};
				board[i][j] = '.';
			}
			if (board[i][j] == 'O') o = {i, j};
		}
	}

	queue<i4> q;
	q.push({r, b});
	dist[r.first][r.second][b.first][b.second] = 0;
	while (!q.empty()) {
		r = q.front().first;
		b = q.front().second;
		q.pop();

		int d = dist[r.first][r.second][b.first][b.second];
		if (d == 10) break;

		rr = r;
		bb = b;
		for (int i = 0; i < 4; ++i) {
			r = rr;
			b = bb;
			int ro = 0, bo = 0;
			while (1) {
				r.first += loc[i][0];
				r.second += loc[i][1];
				if (r.first < 0 || r.first >= n || r.second < 0 || r.second >= m || board[r.first][r.second] == '#') {
					r.first -= loc[i][0];
					r.second -= loc[i][1];
					break;
				}
				if (board[r.first][r.second] == 'O') {
					ro = 1;
					break;
				}
			}
			while (1) {
				b.first += loc[i][0];
				b.second += loc[i][1];
				if (b.first < 0 || b.first >= n || b.second < 0 || b.second >= m || board[b.first][b.second] == '#') {
					b.first -= loc[i][0];
					b.second -= loc[i][1];
					break;
				}
				if (board[b.first][b.second] == 'O') {
					bo = 1;
					break;
				}
			}
			if (bo) continue;
			else if (ro) {
				cout << d + 1;
				return 0;
			}
			else {
				if (r == b) {
					if (i == 0) {
						if (rr.second > bb.second) b.second--;
						else r.second--;
					}
					else if (i == 1) {
						if (rr.second > bb.second) r.second++;
						else b.second++;
					}
					else if (i == 2) {
						if (rr.first > bb.first) b.first--;
						else r.first--;
					}
					else {
						if (rr.first > bb.first) r.first++;
						else b.first++;
					}
				}
				if (dist[r.first][r.second][b.first][b.second] == -1) {
					dist[r.first][r.second][b.first][b.second] = d + 1;
					q.push({r, b});
				}
			}
		}
	}
	cout << -1;
}