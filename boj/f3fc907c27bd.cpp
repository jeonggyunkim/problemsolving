#include <iostream>
using namespace std;

int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, nn;
	cin >> n >> m;
	nn = n * n;

	int x = n / 2 + 1;
	int y = x;
	int ansx, ansy;

	int board[1000][1000];
	int now = 1, cnt = 1, d = 0;
	while (1) {
		for (int i = 0; i < cnt; ++i) {
			if (now == m) {
				ansx = x;
				ansy = y;
			}
			board[y][x] = now++;
			x += dir[d][0];
			y += dir[d][1];
			if (now == nn + 1) goto brk;
		}
		d = (d + 1) % 4;
		for (int i = 0; i < cnt; ++i) {
			if (now == m) {
				ansx = x;
				ansy = y;
			}
			board[y][x] = now++;
			x += dir[d][0];
			y += dir[d][1];
			if (now == nn + 1) goto brk;
		}
		d = (d + 1) % 4;
		cnt++;
	}

	brk:
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cout << board[i][j] << ' ';
		cout << '\n';
	}
	cout << ansy << ' ' << ansx;
}