#include <iostream>
using namespace std;

int loc[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int r, c;
char board[255][255];
bool vis[255][255];
int sheep, wolf;

void dfs(int i, int j) {
	vis[i][j] = 1;
	if (board[i][j] == 'o') sheep++;
	if (board[i][j] == 'v') wolf++;
	for (int k = 0; k < 4; ++k) {
		int x = i + loc[k][0];
		int y = j + loc[k][1];
		if (x < 0 || y < 0 || x >= r || y >= c) continue;
		if (board[x][y] != '#' && !vis[x][y]) dfs(x, y);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i) cin >> board[i];

	int s = 0, w = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (board[i][j] != '#' && !vis[i][j]) {
				sheep = 0, wolf = 0;
				dfs(i, j);
				if (sheep > wolf) s += sheep;
				else w += wolf;
			}
		}
	}
	cout << s << ' ' << w;
}