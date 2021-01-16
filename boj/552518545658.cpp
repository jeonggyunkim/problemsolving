#include <iostream>
#include <memory.h>
using namespace std;

int n, ans;
int board[20][20];
bool stone[20][20];

void up() {
	for (int j = 0; j < n; ++j) {
		for (int i = 1; i < n; ++i) {
			int k = i;
			while (k >= 1) {
				if (!board[k - 1][j]) {
					swap(board[k - 1][j], board[k][j]);
					k--;
				}
				else {
					if (board[k - 1][j] == board[k][j] && !stone[k - 1][j]) {
						board[k - 1][j] *= 2;
						board[k][j] = 0;
						stone[k - 1][j] = 1;
					}
					break;
				}
			}
		}
	}
}

void down() {
	for (int j = 0; j < n; ++j) {
		for (int i = n - 2; i >= 0; --i) {
			int k = i;
			while (k <= n - 2) {
				if (!board[k + 1][j]) {
					swap(board[k + 1][j], board[k][j]);
					k++;
				}
				else {
					if (board[k + 1][j] == board[k][j] && !stone[k + 1][j]) {
						board[k + 1][j] *= 2;
						board[k][j] = 0;
						stone[k + 1][j] = 1;
					}
					break;
				}
			}
		}
	}
}

void left() {
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			int k = j;
			while (k >= 1) {
				if (!board[i][k - 1]) {
					swap(board[i][k - 1], board[i][k]);
					k--;
				}
				else {
					if (board[i][k - 1] == board[i][k] && !stone[i][k - 1]) {
						board[i][k - 1] *= 2;
						board[i][k] = 0;
						stone[i][k - 1] = 1;
					}
					break;
				}
			}
		}
	}
}

void right() {
	for (int i = 0; i < n; ++i) {
		for (int j = n - 2; j >= 0; --j) {
			int k = j;
			while (k <= n - 2) {
				if (!board[i][k + 1]) {
					swap(board[i][k + 1], board[i][k]);
					k++;
				}
				else {
					if (board[i][k + 1] == board[i][k] && !stone[i][k + 1]) {
						board[i][k + 1] *= 2;
						board[i][k] = 0;
						stone[i][k + 1] = 1;
					}
					break;
				}
			}
		}
	}
}

void rec(int mv) {
	if (mv == 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}
	int board_now[20][20];
	memcpy(board_now, board, sizeof(board));

	memset(stone, 0, sizeof(stone));
	up();
	rec(mv - 1);
	memcpy(board, board_now, sizeof(board));
	memset(stone, 0, sizeof(stone));
	down();
	rec(mv - 1);
	memcpy(board, board_now, sizeof(board));
	memset(stone, 0, sizeof(stone));
	left();
	rec(mv - 1);
	memcpy(board, board_now, sizeof(board));
	memset(stone, 0, sizeof(stone));
	right();
	rec(mv - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	rec(5);
	cout << ans;
}