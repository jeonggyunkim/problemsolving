#include <iostream>
using namespace std;

int loc[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int pic[500][500];
bool vis[500][500];
int cnt, n, m;

void dfs(int i, int j) {
	vis[i][j] = 1;
	cnt++;
	for (int k = 0; k < 4; ++k) {
		int x = i + loc[k][0];
		int y = j + loc[k][1];
		if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !pic[x][y]) continue;
		dfs(x, y);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> pic[i][j];
	}

	int ans = 0, maxans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (pic[i][j] && !vis[i][j]) {
				ans++;
				cnt = 0;
				dfs(i, j);
				maxans = max(maxans, cnt);
			}
		}
	}

	cout << ans << '\n' << maxans;
}