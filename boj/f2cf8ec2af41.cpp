#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

char board[12][7];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	for (int i = 0; i < 12; ++i) cin >> board[i];

	int ans = 0;
	while (1) {
		int vis[12][7] = {};
		queue<ii> q;
		vector<int> del;
		int num = 1;

		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (board[i][j] == '.') continue;
				if (!vis[i][j]) {
					int cnt = 0;
					q.push({i, j});
					vis[i][j] = num;
					while (!q.empty()) {
						ii now = q.front(); q.pop();
						cnt++;
						for (int k = 0; k < 4; ++k) {
							int x = now.first + loc[k][0];
							int y = now.second + loc[k][1];
							if (x < 0 || x >= 12 || y < 0 || y >= 6) continue;
							if (!vis[x][y] && board[x][y] == board[now.first][now.second]) {
								q.push({x, y});
								vis[x][y] = num;
							}
						}
					}

					if (cnt >= 4) {
						del.push_back(num);
					}
					num++;
				}
			}
		}

		if (del.size() == 0) break;
		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				for (int u: del) {
					if (vis[i][j] == u) {
						board[i][j] = '.';
					}
				}
			}
		}
		del.clear();
		ans++;

		for (int i = 11; i >= 0; --i) {
			for (int j = 5; j >= 0; --j) {
				int k = i;
				while (k != 11 && board[k][j] != '.' && board[k + 1][j] == '.') {
					swap(board[k][j], board[k + 1][j]);
					k++;
				}
			}
		}
	}
	cout << ans;
}