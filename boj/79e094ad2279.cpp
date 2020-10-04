#include <iostream>

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	char board[52][52];
	for (int i = 0; i < n; ++i) scanf("%s", board + i);
	for (int size = (m > n ? n : m) - 1; size >= 0; --size) {
		for (int i = 0; i < n - size; ++i) {
			for (int j = 0; j < m - size; ++j) {
				if (board[i][j] == board[i + size][j])
				if (board[i + size][j] == board[i][j + size])
				if (board[i][j + size] == board[i + size][j + size]) {
					printf("%d\n", (size + 1) * (size + 1));
					return 0;
				}
			}
		}
	}
	printf("1\n");
}