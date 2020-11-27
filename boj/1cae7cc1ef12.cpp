#include <iostream>
using namespace std;

int ans;
int board[3][3];

void rec(int i, int j) {
	if (j == 3) {
		j = 0;
		i++;
		if (i == 3) {
			ans++;
			return;
		}
	}
	if (board[i][j]) {
		rec(i, j + 1);
	}
	else {
		for (int n = 1; n <= 9; ++n) {
			int pos = 1;
			for (int k = 0; k < 3; ++k) {
				if (board[i][k] == n) pos = 0;
				if (board[k][j] == n) pos = 0;
			}
			if (pos) {
				board[i][j] = n;
				rec(i, j + 1);
				board[i][j] = 0;
			}			
		}
	}
}

int main() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> board[i][j];
		}
	}

	rec(0, 0);
	cout << ans;
}