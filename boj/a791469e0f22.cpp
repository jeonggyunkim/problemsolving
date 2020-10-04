#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int m, n, k;
bool map[100][100];

int dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (map[y][x] == 1) return 0;
	map[y][x] = 1;
	int ret = 1;
	for (int k = 0; k < 4; ++k) ret += dfs(x + dx[k], y + dy[k]);
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	int x1, y1, x2, y2;
	for (int i = 0; i < k; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; ++x) for (int y = y1; y < y2; ++y) map[y][x] = 1;
	}

	int cnt = 0;
	vector<int> area;
	for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) {
		if (map[y][x] == 0) {
			cnt++;
			area.push_back(dfs(x, y));
		}
	}
	sort(area.begin(), area.end());

	cout << cnt << '\n';
	for (int i = 0; i < area.size(); ++i) cout << area[i] << ' ';
}