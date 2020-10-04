#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int arr[200010];
int n;
char board[5][5];
bool hor[5][5], ver[5][5];
int loc[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void draw(int vis) {
	char ans[21][21] = {};
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) ans[i][j] = ' ';
	}

	for (int i = 0; i < 4 * n + 1 + 2; ++i) {
		ans[0][i] = '#';
		ans[2 * n + 2][i] = '#';
	}
	for (int i = 0; i < 2 * n + 1 + 2; ++i) {
		ans[i][0] = '#';
		ans[i][4 * n + 2] = '#';
		ans[i][4 * n + 3] = '\n';
		ans[i][4 * n + 4] = 0;
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			ans[1 + 2 * i][1 + 4 * j] = '+';
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans[2 + 2 * i][3 + 4 * j] = board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (hor[i][j]) ans[2 + 2 * i][1 + 4 * j] = '|';
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (ver[i][j]) {
				for (int k = 0; k < 3; ++k) ans[1 + 2 * i][2 + 4 * j + k] = '-';
			}
		}
	}

	for (int i = 0; i < 2 * n + 3; ++i) cout << ans[i];
}

bool isAns() {
	bool vis[5][5] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != '.' && !vis[i][j]) {
				char ani = board[i][j];
				queue<ii> q;
				q.push({i, j});
				vis[i][j] = 1;
				bool imp = 0;
				while (!q.empty()) {
					ii now = q.front(); q.pop();
					int x = now.first, y = now.second;
					if (board[x][y] != '.' && board[x][y] != ani) imp = 1;
					for (int k = 0; k < 4; ++k) {
						int xx = x + loc[k][0];
						int yy = y + loc[k][1];

						if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
						if (vis[xx][yy]) continue;
						if (k == 0 && !hor[x][y]) {
							q.push({xx, yy});
							vis[xx][yy] = 1;
						}
						else if (k == 1 && !hor[x][y + 1]) {
							q.push({xx, yy});
							vis[xx][yy] = 1;
						}
						else if (k == 2 && !ver[x][y]) {
							q.push({xx, yy});
							vis[xx][yy] = 1;
						}
						else if (k == 3 && !ver[x + 1][y]) {
							q.push({xx, yy});
							vis[xx][yy] = 1;
						}
					}
				}
				if (imp) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void check(int vis) {
	if (isAns()) {
		cout << "yes\n";
		draw(vis);
		exit(0);
	}
}

void visit(int i, int j, int vis) {
	vis ^= (1 << (i * 5 + j));
	if (i == n && j == n) {
		check(vis);
		return;
	}
	for (int k = 0; k < 4; ++k) {
		int xx = i + loc[k][0];
		int yy = j + loc[k][1];

		if (xx < 0 || xx > n || yy < 0 || yy > n) continue;
		if (vis & (1 << (xx * 5 + yy))) continue;

		if (k == 0) ver[i][j - 1] = 1;
		else if (k == 1) ver[i][j] = 1;
		else if (k == 2) hor[i - 1][j] = 1;
		else hor[i][j] = 1;

		visit(xx, yy, vis);

		if (k == 0) ver[i][j - 1] = 0;
		else if (k == 1) ver[i][j] = 0;
		else if (k == 2) hor[i - 1][j] = 0;
		else hor[i][j] = 0;
	}
	vis ^= (1 << (i * 5 + j));
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> board[i];

	visit(0, 0, 0);
	cout << "no";
}