#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int board[100][100];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0},{-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 0) {
				int cnt = 0;
				queue<ii> q;
				q.push({i, j});
				board[i][j] = 1;
				cnt++;
				while (!q.empty()) {
					ii now = q.front(); q.pop();
					for (int k = 0; k < 4; ++k) {
						int x = now.first + loc[k][0];
						int y = now.second + loc[k][1];
						if (x < 0 || x >= n || y < 0 || y >= n || board[x][y] == 1) continue;
						q.push({x, y});
						board[x][y] = 1;
						cnt++;
					}
				}
				ans += (cnt + k - 1) / k;
			}
		}
	}
	if (ans && ans <= m) cout << "POSSIBLE\n" << m - ans;
	else cout << "IMPOSSIBLE";
}