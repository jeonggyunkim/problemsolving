#include <iostream>
#include <set>
using namespace std;

char board[220][220];
int block[200][200];
bool vis[100][100];
int counter = 1;
int n, m;

int loc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool dfs(int i, int j) {
	vis[i][j] = 1;

	int ii = 2 * i + 1;
	int jj = 2 * j + 1;
	if (board[ii][jj] == 'B') {
		block[2 * i][2 * j] = counter;
		block[2 * i + 1][2 * j] = counter;
		block[2 * i][2 * j + 1] = counter;
		block[2 * i + 1][2 * j + 1] = counter;
	}
	else return 0;

	for (int k = 0; k < 4; ++k) {
		int x = i + loc[k][0];
		int y = j + loc[k][1];
		if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) continue;

		int xx = 2 * x + 1;
		int yy = 2 * y + 1;

		if (board[xx][yy] == 'B' && board[ii + loc[k][0]][jj + loc[k][1]] == '.') dfs(x, y);
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string k;
	cin >> n >> m >> k;

	for (int i = 0; i < 2 * m + 1; ++i) cin >> board[i];

	for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
		if (!vis[i][j]) {
			if (dfs(i, j)) counter++;
		}
	}

	set<int> cnt;
	n *= 2; m *= 2;
	int x = m - 1, y;
	if (k.size() >= 2 && k[k.size() - 2] == '.') {
		k.pop_back(); k.pop_back();
		y = 2 * atoi(k.c_str());
	}
	else {
		y = 2 * atoi(k.c_str()) - 1;
	}
	while (1) {
		int rx = x, ry = y;
		if (x < 0) {
			int t = -x - 1;
			if ((t / m) & 1) rx = m - 1 - t % m;
			else rx = t % m;
		}
		if (y < 0) {
			int t = -y - 1;
			if ((t / n) & 1) ry = n - 1 - t % n;
			else ry = t % n;
		}
		if (block[rx][ry]) cnt.insert(block[rx][ry]);
		if (rx == m - 1 && x != m - 1) break;

		x--; y--;
	}
	cout << cnt.size();
}