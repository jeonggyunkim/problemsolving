#include <iostream>
#include <vector>
using namespace std;

int loc[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int board[102][102];
int ans[102][102];

int blk[2][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dir = 1, flip = 0;
	for (int i: {0, 1}) for (int j: {0, 1}) {
		blk[i][j] = 2 * i + j;
	}

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	int op;
	while (r--) {
		cin >> op;
		switch (op) {
			case 1:
			swap(blk[0][0], blk[1][0]);
			swap(blk[0][1], blk[1][1]);
			if (dir % 2 == 1) (dir += 2) %= 4;
			flip = 1 - flip;
			break;
			case 2:
			swap(blk[0][0], blk[0][1]);
			swap(blk[1][0], blk[1][1]);
			if (dir % 2 == 0) (dir += 2) %= 4;
			flip = 1 - flip;
			break;
			case 3:
			(dir += 3) %= 4;
			case 5:
			swap(blk[0][0], blk[0][1]);
			swap(blk[1][0], blk[0][0]);
			swap(blk[1][1], blk[1][0]);
			break;
			case 4:
			(dir += 1) %= 4;
			case 6:
			swap(blk[0][0], blk[0][1]);
			swap(blk[0][1], blk[1][1]);
			swap(blk[1][1], blk[1][0]);
			break;
		}
	}

	int start[2][4][2] = {
		{{0, n / 2 - 1}, {0, 0}, {m / 2 - 1, 0}, {n / 2 - 1, m / 2 - 1}},
		{{m / 2 - 1, n / 2 - 1}, {0, m / 2 - 1}, {0, 0}, {n / 2 - 1, 0}},
	};
	int dx[2][4][2] = {
		{{0, -1}, {1, 0}, {0, 1}, {-1, 0}},
		{{0, -1}, {1, 0}, {0, 1}, {-1, 0}},
		//{{0, 1}, {-1, 0}, {0, -1}, {1, 0}},
	};
	int dy[2][4][2] = {
		{{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
		{{-1, 0}, {0, -1}, {1, 0}, {0, 1}},
	};

	for (int i: {0, 1}) for (int j: {0, 1}) {
		int sx = start[flip][dir][0], sy = start[flip][dir][1];
		if (dir % 2) {
			sx += (n / 2) * i;
			sy += (m / 2) * j;
		}
		else {
			sx += (m / 2) * i;
			sy += (n / 2) * j;
		}
		for (int x = 0; x < n / 2; ++x) {
			for (int y = 0; y < m / 2; ++y) {
				ans[sx + dx[flip][dir][0] * x + dy[flip][dir][0] * y][sy + dx[flip][dir][1] * x + dy[flip][dir][1] * y]
				= board[(blk[i][j] / 2) * (n / 2) + x][(blk[i][j] % 2) * (m / 2) + y];
			}
		}
	}

	if (dir % 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}