#include <iostream>
using namespace std;

int n;
int loc[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void rec(int board[10][10], int cnt) {
	if (cnt == 1) {
		cout << "Possible";
		exit(0);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 2) {
				for (int k = 0; k < 8; ++k) {
					int x = i + 2 * loc[k][0];
					int y = j + 2 * loc[k][1];
					if (x < 0 || x >= n || y < 0 || y >= n) continue;
					if (board[x][y] == 0 && board[x - loc[k][0]][y - loc[k][1]] == 2) {
						board[x][y] = 2;
						board[x - loc[k][0]][y - loc[k][1]] = 0;
						board[i][j] = 0;
						rec(board, cnt - 1);
						board[i][j] = 2;
						board[x - loc[k][0]][y - loc[k][1]] = 2;
						board[x][y] = 0;
					}

				}
			}
		}
	}
}

int main() {
	cin >> n;

	int cnt = 0;
	int board[10][10];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2) cnt++;
		}
	}

	rec(board, cnt);

	cout << "Impossible";
}