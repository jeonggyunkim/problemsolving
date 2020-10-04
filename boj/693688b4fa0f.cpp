#include <iostream>
using namespace std;

int n, ans;
int dir[6][2] = {{0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 0}};
bool vis[47][47];

void dfs(int x, int y, int dep, int d) {
	if (dep == n) {
		if (vis[x][y]) ans++;
		return;
	}
	if (vis[x][y]) return;
	vis[x][y] = 1;
	int r = (d + 1) % 6, l = (d + 5) % 6;
	dfs(x + dir[r][0], y + dir[r][1], dep + 1, r);
	dfs(x + dir[l][0], y + dir[l][1], dep + 1, l);
	vis[x][y] = 0;
}

int main() {
	cin >> n;

	vis[23][23] = 1;
	dfs(23, 24, 0, 0);

	cout << ans;
}