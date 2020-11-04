#include <iostream>
using namespace std;

char board[10][11];

int main() {
	for (int i = 0; i < 10; ++i) cin >> board[i];

	int a = 24, b = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i * 3][1 + 3 * j] == '-') a--;
			if (board[1 + 3 * j][i * 3] == '|') a--;
		}
	}

	for (int sz = 1; sz <= 3; ++sz) {
		for (int i = 0; i < 4 - sz; ++i) {
			for (int j = 0; j < 4 - sz; ++j) {
				int pos = 1;
				for (int k = 0; k < sz; ++k) {
					if (board[i * 3][1 + 3 * (j + k)] != '-') pos = 0;
					if (board[(i + sz) * 3][1 + 3 * (j + k)] != '-') pos = 0;
					if (board[1 + (i + k) * 3][3 * j] != '|') pos = 0;
					if (board[1 + (i + k) * 3][3 * (j + sz)] != '|') pos = 0;
				}
				if (pos) b++;
			}
		}
	}
	
	cout << a << ' ' << b;
}