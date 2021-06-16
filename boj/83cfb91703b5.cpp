#include <iostream>
#include <memory.h>
using namespace std;

int board[100][100];
int shark[10001][6];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, m;
	cin >> r >> c >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		x--; y--;
		board[x][y] = i;
		shark[i][0] = x;
		shark[i][1] = y;
		shark[i][2] = s;
		shark[i][3] = d;
		shark[i][4] = z;
		shark[i][5] = 1;
	}

	int ans = 0;
	for (int i = 0; i < c; ++i) {
		int num = -1;
		for (int j = 0; j < r; ++j) {
			if (board[j][i] != 0) {
				num = board[j][i];
				break;
			}
		}

		if (num != -1) {
			ans += shark[num][4];
			shark[num][5] = 0;
			board[shark[num][0]][shark[num][1]] = 0;
		}

		memset(board, 0, sizeof(board));
		for (int i = 1; i <= m; ++i) {
			if (shark[i][5]) {
				int x = shark[i][0];
				int y = shark[i][1];
				int v = shark[i][2];
				int d = shark[i][3];
				// move

				if (d <= 2) v %= (2 * (r - 1));
				else v %= (2 * (c - 1));

				while (v) {
					if (d == 1) {
						int p = min(v, x);
						x -= p;
						v -= p;
						if (x == 0) d = 2;
					}
					else if (d == 2) {
						int p = min(v, r - 1 - x);
						x += p;
						v -= p;
						if (x == r - 1) d = 1;
					}
					else if (d == 3) {
						int p = min(v, c - 1 - y);
						y += p;
						v -= p;
						if (y == c - 1) d = 4;
					}
					else if (d == 4) {
						int p = min(v, y);
						y -= p;
						v -= p;
						if (y == 0) d = 3;
					}
				}

				if (board[x][y] != 0) {
					int another = board[x][y];
					if (shark[another][4] > shark[i][4]) {
						shark[i][5] = 0;
					}
					else {
						board[x][y] = i;
						shark[another][5] = 0;
						shark[i][0] = x;
						shark[i][1] = y;
						shark[i][3] = d;
					}
				}
				else {
					board[x][y] = i;
					shark[i][0] = x;
					shark[i][1] = y;
					shark[i][3] = d;
				}
			}
		}
	}
	cout << ans;
}