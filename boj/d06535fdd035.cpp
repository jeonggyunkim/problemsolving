#include <iostream>

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	char board[52][52];
	for (int i = 0; i < n; ++i) scanf("%s", board + i);
	int mask[52][52];
	for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == 'B') t |= (1 << (7 - j));
		}
		mask[i][0] = t;
		for (int j = 0; j < m - 8; ++j) {
			t = (t << 1) & ((1 << 8) - 1);
			if (board[i][8 + j] == 'B') t |= 1;
			mask[i][j + 1] = t;
		}
	}
	unsigned long long check;
	unsigned long long s = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 4; ++j) {
			s <<= 2;
			if (i & 1) s |= 1;
			else s |= 2;
		}
	}
	int min = 100, cnt;
	for (int i = 0; i < n - 7; ++i) {
		for (int j = 0; j < m - 7; ++j) {
			check = 0;
			for (int k = 0; k < 8; ++k) {
				check <<= 8;
				check |= mask[i + k][j];
			}
			check ^= s;
			cnt = 0;
			while (check) {
				if (check & 1) cnt++;
				check >>= 1;
			}
			if (cnt > 32) cnt = 64 - cnt;
			if (cnt < min) min = cnt;
		}
	}
	printf("%d\n", min);
}