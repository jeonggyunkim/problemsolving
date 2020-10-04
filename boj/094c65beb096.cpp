#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int n;
int d[100][100];
int num[100][100];
bool vis[100][100];

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, int d) {
	vis[i][j] = 1;
	num[i][j] = d;
	for (int k = 0; k < 4; ++k) {
		int x = i + dir[k][0];
		int y = j + dir[k][1];
		if (x < 0 || x >= n || y < 0 || y >= n) continue;
		if (!vis[x][y] && num[x][y]) dfs(x, y, d);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		cin >> num[i][j];

	int counter = 2;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		if (!vis[i][j] && num[i][j] == 1) dfs(i, j, counter++);

	memset(vis, 0, sizeof(vis));

	queue<ii> q;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		if (num[i][j]) {
			vis[i][j] = 1;
			q.push(ii(i, j));
		}
	}

	int brk = -1;
	int ans = 98765;
	while (!q.empty()) {
		ii now = q.front(); q.pop();
		int i = now.first;
		int j = now.second;
		if (brk != -1 && d[i][j] > brk) break;
		for (int k = 0; k < 4; ++k) {
			int x = i + dir[k][0];
			int y = j + dir[k][1];
			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (!vis[x][y]) {
				vis[x][y] = 1;
				d[x][y] = d[i][j] + 1;
				num[x][y] = num[i][j];
				q.push(ii(x, y));
			}
			if (num[x][y] != num[i][j]) {
				ans = min(ans, d[i][j] + d[x][y]);
				brk = d[i][j];
			}
		}
	}

	cout << ans;
}