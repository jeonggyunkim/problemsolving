#include <iostream>

int shape[4][2][2] =
{ { { 0, 1 },{ 1, 1 } },
{ { 1, 0 },{ 1, 1 } },
{ { 0, 1 },{ 1, 0 } },
{ { -1, 1 },{ 0, 1 } } };

int h, w, cnt;
bool board[20][20];

bool canplace(int x, int y, int type) {
	for (int i = 0; i < 2; ++i) {
		if (x + shape[type][i][0] < 0 || x + shape[type][i][0] >= w) return false;
		if (y + shape[type][i][1] < 0 || y + shape[type][i][1] >= h) return false;
		if (board[y + shape[type][i][1]][x + shape[type][i][0]] == 1) return false;
	}
	return true;
}

void place(int x, int y) {
	board[y][x] = 1;
	for (int type = 0; type < 4; ++type) {
		if (canplace(x, y, type)) {
			board[y + shape[type][0][1]][x + shape[type][0][0]] = 1;
			board[y + shape[type][1][1]][x + shape[type][1][0]] = 1;
			int nx = x, ny = y;
			while (true) {
				if (nx == w) {
					nx = 0;
					ny++;
				}
				if (ny == h) {
					cnt++;
					break;
				}
				if (board[ny][nx] == 0) {
					place(nx, ny);
					break;
				}
				nx++;
			}
			board[y + shape[type][0][1]][x + shape[type][0][0]] = 0;
			board[y + shape[type][1][1]][x + shape[type][1][0]] = 0;
		}
	}
	board[y][x] = 0;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &h, &w);
		char buf[20];
		for (int i = 0; i < h; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < w; ++j) board[i][j] = (buf[j] == '#' ? 1 : 0);
		}
		cnt = 0;
		int i = 0, j = 0;
		while (true) {
			if (i == w) {
				i = 0;
				j++;
			}
			if (j == h) break;
			if (board[j][i] == 0) {
				place(i, j);
				break;
			}
			i++;
		}

		printf("%d\n", cnt);
	}
}
