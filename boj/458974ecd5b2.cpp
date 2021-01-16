#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char board[50][51];
int d[50][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		vector<ii> pos(2);

		int n, m, t;
		cin >> n >> m >> t;

		for (int i = 0; i < n; ++i) {
			cin >> board[i];
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'K') {
					pos[0] = {i, j};
				}
				else if (board[i][j] == 'Q') {
					pos[1] = {i, j};
				}
				else if (board[i][j] == 'G') {
					pos.push_back({i, j});
				}
			}
		}

		vector<vector<int>> dist(pos.size(), vector<int>(pos.size(), -1));

		for (int i = 0; i < pos.size(); ++i) {
			memset(d, -1, sizeof(d));

			queue<ii> q;
			d[pos[i].first][pos[i].second] = 0;
			q.push(pos[i]);
			while (!q.empty()) {
				ii now = q.front(); q.pop();

				if (board[now.first][now.second] >= 'A') {
					for (int j = 0; j < pos.size(); ++j) {
						if (pos[j] == now) {
							dist[i][j] = d[now.first][now.second];
							break;
						}
					}
				}
				for (int k = 0; k < 4; ++k) {
					int x = now.first + loc[k][0];
					int y = now.second + loc[k][1];
					if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#') continue;
					if (d[x][y] == -1) {
						d[x][y] = d[now.first][now.second] + 1;
						q.push({x, y});
					}
				}
			}
		}

		vector<vector<int>> dp(1 << (pos.size() - 2), vector<int>(pos.size(), INF));
		dp[0][0] = 0;
		for (int mask = 0; mask < (1 << (pos.size() - 2)); ++mask) {
			int price = __builtin_popcount(mask) + 1;
			for (int now = 0; now < pos.size(); ++now) {
				if (dp[mask][now] == INF) continue;
				for (int k = 1; k < pos.size(); ++k) {
					int newmask;
					if (k == now || dist[now][k] == -1) continue;
				
					if (k == 1) {
						newmask = mask;
					}
					else {
						newmask = mask | (1 << (k - 2));
					}
					dp[newmask][k] = min(dp[newmask][k], dp[mask][now] + price * dist[now][k]);
				}
			}
		}

		int ans = 0;
		for (int mask = 0; mask < (1 << (pos.size() - 2)); ++mask) {
			if (dp[mask][1] <= t) {
				ans = max(ans, __builtin_popcount(mask));
			}
		}
		cout << ans << '\n';;
	}
}