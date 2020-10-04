#include <iostream>
#include <memory.h>
using namespace std;

int board[3][3];
int t[3][3];

void build(int sum) {
	memcpy(t, board, sizeof(board));
	int x, y;
	for (int i = 0; i < 3; ++i) {
		int z = 0, now = 0;
		for (int j = 0; j < 3; ++j) {
			if (t[i][j] == 0) {
				z++;
				x = i; y = j;
			}
			now += t[i][j];
		}
		if (z == 1) t[x][y] = sum - now;
		
		z = 0; now = 0;
		for (int j = 0; j < 3; ++j) {
			if (t[j][i] == 0) {
				z++;
				x = j; y = i;
			}
			now += t[j][i];
		}
		if (z == 1) t[x][y] = sum - now;

		if (i == 0) {
			z = 0; now = 0;
			for (int j = 0; j < 3; ++j) {
				if (t[j][j] == 0) {
					z++;
					x = j; y = j;
				}
				now += t[j][j];
			}
			if (z == 1) t[x][y] = sum - now;

			z = 0; now = 0;
			for (int j = 0; j < 3; ++j) {
				if (t[j][2 - j] == 0) {
					z++;
					x = j; y = 2 - j;
				}
				now += t[j][2 - j];
			}
			if (z == 1) t[x][y] = sum - now;
		}
	}
}

int check() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (t[i][j] < 0) return 0;
		}
	}

	int sum = 0;
	for (int i = 0; i < 3; ++i) sum += t[i][i];

	int now = 0;
	for (int i = 0; i < 3; ++i) now += t[i][2 - i];
	if (sum != now) return 0;

	for (int i = 0; i < 3; ++i) {
		now = 0;
		for (int j = 0; j < 3; ++j) now += t[i][j];
		if (sum != now) return 0;

		now = 0;
		for (int j = 0; j < 3; ++j) now += t[j][i];
		if (sum != now) return 0;
	}

	return 1;
}

void print() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> board[i][j];
		}
	}
	int x, y, sum, det = 0;
	for (int i = 0; i < 3; ++i) {
		int z = 0, now = 0;
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0) {
				z++;
				x = i; y = j;
			}
			now += board[i][j];
		}
		if (z == 0 || z == 1) {
			if (z == 0) det = 1;
			sum = now;
			break;
		}
		
		z = 0; now = 0;
		for (int j = 0; j < 3; ++j) {
			if (board[j][i] == 0) {
				z++;
				x = j; y = i;
			}
			now += board[j][i];
		}
		if (z == 0 || z == 1) {
			if (z == 0) det = 1;
			sum = now;
			break;
		}

		if (i == 0) {
			z = 0; now = 0;
			for (int j = 0; j < 3; ++j) {
				if (board[j][j] == 0) {
					z++;
					x = j; y = j;
				}
				now += board[j][j];
			}
			if (z == 0 || z == 1) {
				if (z == 0) det = 1;
				sum = now;
				break;
			}

			z = 0; now = 0;
			for (int j = 0; j < 3; ++j) {
				if (board[j][2 - j] == 0) {
					z++;
					x = j; y = 2 - j;
				}
				now += board[j][2 - j];
			}
			if (z == 0 || z == 1) {
				if (z == 0) det = 1;
				sum = now;
				break;
			}
		}
	}

	if (det) {
		build(sum);
		if (check()) {
			print();
			return 0;
		}
	}

	for (int n = 1; n <= 20000; ++n) {
		board[x][y] = n;
		build(sum + n);
		if (check()) {
			print();
			return 0;
		}
	}
}