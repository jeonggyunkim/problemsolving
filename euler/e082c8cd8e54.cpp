#include <iostream>
using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int board[1001][1001];

int main() {
	int x = 500, y = 500;
	board[x][y] = 1;
	int nn = 1001 * 1001, d = 0, num = 1, cnt = 1;

	while (1) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < num; ++j) {
				x += dir[d][0];
				y += dir[d][1];
				board[y][x] = ++cnt;
				if (cnt == nn) goto brk;
			}
			d = (d + 1) % 4;
		}
		num++;
	}
	
	brk:
	int ans = 0;
	for (int i = 0; i < 1001; ++i) ans += board[i][i];
	for (int i = 0; i < 1001; ++i) ans += board[1000 - i][i];
	ans--;
	cout << ans << endl;
}