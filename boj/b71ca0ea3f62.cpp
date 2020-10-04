#include <iostream>
#include <memory.h>
using namespace std;

int board[100][100];
int nextboard[100][100];
int loc[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c, k;
	while (cin >> n >> r >> c >> k, n) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) cin >> board[i][j];
		}

		for (int rep = 0; rep < k; ++rep) {
			memset(nextboard, -1, sizeof(nextboard));
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					for (int a = 0; a < 4; ++a) {
						int x = i + loc[a][0];
						int y = j + loc[a][1];
						if (x < 0 || x >= r || y < 0 || y >= c) continue;
						if ((board[x][y] - board[i][j] + n) % n == 1) nextboard[x][y] = board[i][j];
					}
				}
			}
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					if (nextboard[i][j] != -1) board[i][j] = nextboard[i][j];
				}
			}
		}

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) cout << board[i][j] << ' ';
			cout << '\n';
		}
	}
}
