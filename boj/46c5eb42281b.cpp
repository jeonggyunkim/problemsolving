#include <iostream>
#include <queue>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char arr[102][102];
int key;
char keys[30];
bool vis[102][102];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; ++i) cin >> &arr[i][1];
		for (int i = 0; i <= n + 1; ++i) arr[i][0] = arr[i][m + 1] = '.';
		for (int j = 0; j <= m + 1; ++j) arr[0][j] = arr[n + 1][j] = '.';
		cin >> keys;

		int key = 0;
		if (keys[0] != '0') {
			for (int i = 0; keys[i]; ++i) key |= (1 << (keys[i] - 'a'));
		}

		while (1) {
			bool findkey = 0;
			int ans = 0;
			queue<ii> q;
			memset(vis, 0, sizeof(vis));
			q.push({0, 0});
			vis[0][0] = 1;

			while (!q.empty()) {
				ii now = q.front(); q.pop();
				int i = now.first, j = now.second;
				for (int k = 0; k < 4; ++k) {
					int x = i + loc[k][0], y = j + loc[k][1];
					if (x < 0 || x >= n + 2 || y < 0 || y >= m + 2 || vis[x][y]) continue;

					if (arr[x][y] == '.') {
						q.push({x, y});
						vis[x][y] = 1;
					}
					else if (arr[x][y] >= 'A' && arr[x][y] <= 'Z') {
						if (key & (1 << (arr[x][y] - 'A'))) {
							q.push({x, y});
							vis[x][y] = 1;
						}
					}
					else if (arr[x][y] >= 'a' && arr[x][y] <= 'z') {
						if (key & (1 << (arr[x][y] - 'a'))) {
							q.push({x, y});
							vis[x][y] = 1;
						}
						else {
							key |= (1 << (arr[x][y] - 'a'));
							findkey = 1;
							goto clear;
						}
					}
					else if (arr[x][y] == '$') {
						q.push({x, y});
						vis[x][y] = 1;
						ans++;
					}
				}
			}

			clear:
			if (!findkey) {
				cout << ans << '\n';
				break;
			}
		}
	}
}