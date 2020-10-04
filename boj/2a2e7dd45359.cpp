#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n + 2, vector<int>(m + 2, 0));

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) cnt++;
		}
	}

	int ans = 0;
	while (cnt) {
		queue<ii> q;
		vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, 0));
		q.push({0, 0});
		vis[0][0] = 1;

		while (!q.empty()) {
			ii now = q.front(); q.pop();
			int i = now.first, j = now.second;
			for (int k = 0; k < 4; ++k) {
				int x = i + loc[k][0];
				int y = j + loc[k][1];

				if (x < 0 || x >= n + 2 || y < 0 || y >= m + 2) continue;

				if (!vis[x][y] && board[x][y] == 0) {
					board[x][y] = 2;
					vis[x][y] = 1;
					q.push({x, y});
				}
			}
		}

		for (int i = 0; i < n + 2; ++i) {
			for (int j = 0; j < m + 2; ++j) {
				if (board[i][j] == 1) {
					int adj = 0;
					for (int k = 0; k < 4; ++k) {
						if (board[i + loc[k][0]][j + loc[k][1]] == 2) adj++;
					}
					if (adj >= 2) {
						board[i][j] = 0;
						cnt--;
					}
				}
			}
		}

		for (int i = 0; i < n + 2; ++i) {
			for (int j = 0; j < m + 2; ++j) {
				if (board[i][j] == 2) board[i][j] = 0;
			}
		}

		ans++;
	}
	cout << ans;
}