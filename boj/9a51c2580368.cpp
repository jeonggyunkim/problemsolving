#include <iostream>
#include <memory.h>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

char board[101][101];
char s[30];
int dp[100][100][26];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	int n, m, s_size;
	cin >> n >> m >> s_size;

	cin >> s;

	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}

	queue<iii> q;
	q.push({0, 0, 0});
	dp[0][0][0] = s_size == 1;
	while (!q.empty()) {
		iii now = q.front(); q.pop();
		int i, j, k;
		tie(i, j, k) = now;
		int d = dp[i][j][k];
		if (d > 5000) {
			cout << -1;
			return 0;
		}
		for (int l = 0; l < 4; ++l) {
			int x = i + loc[l][0];
			int y = j + loc[l][1];

			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (board[x][y] != s[(k + 1) % s_size]) continue;

			int dd = d, kk = (k + 1) % s_size;
			if (kk == s_size - 1) dd++;

			if (dp[x][y][kk] < dd) {
				dp[x][y][kk] = dd;
				q.push({x, y, kk});
			}
		}
	}

	int maxans = -1, x, y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dp[i][j][s_size - 1] > maxans) {
				maxans = dp[i][j][s_size - 1];
				x = i;
				y = j;
			}
		}
	}
	if (maxans <= 0) {
		cout << -1;
	}
	else {
		cout << maxans << '\n';
		cout << x + 1 << ' ' << y + 1;
	}
}