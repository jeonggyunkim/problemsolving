#include <iostream>
#include <memory.h>
using namespace std;

int dp[1 << 21];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int ans(char board[5][5]) {
	int cnt = 0, mask = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == '#') continue;
			if (board[i][j] == 'o') mask |= (1 << cnt);
			cnt++;
		}
	}

	int ret = __builtin_popcount(mask);
	if (ret == 1) return dp[mask] = ret;
	if (dp[mask] != -1) return dp[mask];

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[i][j] == 'o') {
				for (int k = 0; k < 4; ++k) {
					int x = i + loc[k][0];
					int y = j + loc[k][1];
					int xx = i + 2 * loc[k][0];
					int yy = j + 2 * loc[k][1];
					if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5) continue;
					if (board[xx][yy] == '#' || board[x][y] == '#') continue;
					if (board[x][y] == 'o' && board[xx][yy] == '.') {
						board[i][j] = '.';
						board[x][y] = '.';
						board[xx][yy] = 'o';

						ret = min(ret, ans(board));

						board[i][j] = 'o';
						board[x][y] = 'o';
						board[xx][yy] = '.';
					}
				}
			}
		}
	}
	return dp[mask] = ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		memset(dp, -1, sizeof(dp));

		char board[6][5];
		for (int i = 0; i < 5; ++i) cin >> board[i];
		printf("The best case ends with %d pegs.\n", ans(board));
	}
}