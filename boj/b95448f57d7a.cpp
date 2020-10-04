#include <iostream>

int mv1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int mv2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int w, h;
int board[50][50];

void search(int y, int x) {
	if (x < 0 || x >= w || y < 0 || y >= h) return;
	if (board[y][x] != 1) return;
	board[y][x] = 2;
	for (int i = 0; i < 8; ++i) search(y + mv1[i], x + mv2[i]);
}

int main() {
	while (scanf("%d %d", &w, &h), w || h) {
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) scanf("%d", &board[i][j]);

		int cnt = 0;
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			if (board[i][j] == 1) cnt++;
			search(i, j);
		}
		printf("%d\n", cnt);
	}
}