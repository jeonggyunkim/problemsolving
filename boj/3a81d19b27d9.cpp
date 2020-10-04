#include <iostream>
using namespace std;

char board[7][8];

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	for (int i = 0; i < 7; ++i) {
		cin.getline(board[i], 8);
	}

	int ans = 0;
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			if ((i < 2 || i >= 5) && (j < 2 || j >= 5)) continue;
			if (board[i][j] == 'o') {
				for (int k = 0; k < 4; ++k) {
					int x = i + 2 * loc[k][0];
					int y = j + 2 * loc[k][1];
					if (x < 0 || x >= 7 || y < 0 || y >= 7) continue;
					if ((x < 2 || x >= 5) && (y < 2 || y >= 5)) continue;
					if (board[i + loc[k][0]][j + loc[k][1]] == 'o' && board[x][y] == '.') ans++;
				}
			}
		}
	}
	cout << ans;
}