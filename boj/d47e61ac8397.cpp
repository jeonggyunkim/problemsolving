#include <iostream>
using namespace std;

int r, c, k, ans;
bool vis[5][5];
char board[5][6];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, int d) {
	if (i == 0 && j == c - 1) {
		if (d == k) ans++;
		return;
	}
	vis[i][j] = 1;
	for (int x = 0; x < 4; ++x) {
		int ii = i + loc[x][0];
		int jj = j + loc[x][1];
		if (ii < 0 || ii >= r || jj < 0 || jj >= c) continue;
		if (board[ii][jj] == 'T' || vis[ii][jj]) continue;
		dfs(ii, jj, d + 1);
	}
	vis[i][j] = 0;
}

int main() {
	cin >> r >> c >> k;

	for (int i = 0; i < r; ++i) cin >> board[i];
	dfs(r - 1, 0, 1);

	cout << ans;
}