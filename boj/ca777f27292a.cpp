#include <iostream>
#define INF 987654321
using namespace std;

int loc[6][2] = {{0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, 0}, {-1, 0}};

int solve(int board[5][5]) {
	int now = -INF;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (!board[i][j]) continue;
			for (int k = 0; k < 6; ++k) {
				int x = i + loc[k][0];
				int y = j + loc[k][1];
				int xx = i + 2 * loc[k][0];
				int yy = j + 2 * loc[k][1];
				if (xx < 0 || xx >= 5 || yy < 0 || yy > xx) continue;
				if (board[x][y] && !board[xx][yy]) {
					int score = board[i][j] * board[x][y];

					int t = board[x][y];
					board[x][y] = 0;
					board[xx][yy] = board[i][j];
					board[i][j] = 0;

					score -= solve(board);

					board[x][y] = t;
					board[i][j] = board[xx][yy];
					board[xx][yy] = 0;

					now = max(now, score);
				}
			}
		}
	}
	if (now == -INF) return 0;
	else return now;
}

int main() {
	int board[5][5];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> board[i][j];
		}
	}

	cout << solve(board);
}