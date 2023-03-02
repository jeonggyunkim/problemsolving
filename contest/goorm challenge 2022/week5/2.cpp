#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int arr[100][100];
int nxt[100][100];
bool vis[100][100];
int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		int change = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == 0) nxt[i][j] = 0;
				else {
					int find = 0;
					for (int k = 0; k < 4; ++k) {
						int x = i + loc[k][0];
						int y = j + loc[k][1];
						if (x < 0 || x >= n || y < 0 || y >= m) continue;
						if (arr[x][y] == 0) find = 1;
					}
					if (find) {
						nxt[i][j] = 0;
						change = 1;
					}
					else nxt[i][j] = 1;
				}
			}
		}
		if (!change) {
			cout << -1;
			break;
		}
		ans++;

		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (cnt <= 1 && nxt[i][j] == 1 && !vis[i][j]) {
					if (cnt) {
						cnt++;
						break;
					}
					cnt++;
					queue<ii> q;
					q.push({i, j});
					vis[i][j] = 1;
					while (!q.empty()) {
						ii now = q.front(); q.pop();
						for (int k = 0; k < 4; ++k) {
							int x = now.first + loc[k][0];
							int y = now.second + loc[k][1];
							if (x < 0 || x >= n || y < 0 || y >= m) continue;
							if (!vis[x][y] && nxt[x][y] == 1) {
								q.push({x, y});
								vis[x][y] = 1;
							}
						}
					}
				}
			}
		}
		if (cnt == 2) {
			cout << ans;
			break;
		}
		memcpy(arr, nxt, sizeof(arr));
	}
}