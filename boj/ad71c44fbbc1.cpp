#include <iostream>
using namespace std;

char board[10][11];

int main() {
	int bx, by, lx, ly;
	for (int i = 0; i < 10; ++i) cin >> board[i];
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (board[i][j] == 'B') {
				bx = i; by = j;
			}
			if (board[i][j] == 'L') {
				lx = i; ly = j;
			}
		}
	}

	int ans = abs(lx - bx) + abs(ly - by);
	if (lx == bx) {
		for (int i = min(ly, by) + 1; i < max(ly, by); ++i) {
			if (board[lx][i] == 'R') ans += 2;
		}
	}
	else if (ly == by) {
		for (int i = min(lx, bx) + 1; i < max(lx, bx); ++i) {
			if (board[i][ly] == 'R') ans += 2;
		}
	}
	cout << ans - 1;
}