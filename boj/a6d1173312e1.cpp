#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool inq[100][100];
int water[100][100];
int area[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	queue<ii> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> area[i][j];
			water[i][j] = 10000;
			inq[i][j] = 1;
			q.push({i, j});
		}
	}

	while (!q.empty()) {
		ii now = q.front(); q.pop();
		int i = now.first, j = now.second;
		inq[i][j] = 0;
		bool cng = 0;
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
			if (water[i][j] > area[i][j]) {
				water[i][j] = area[i][j];
				cng = 1;
			}
		}
		else {
			int before = water[i][j];
			for (int k = 0; k < 4; ++k) {
				int x = i + loc[k][0];
				int y = j + loc[k][1];
				if (water[x][y] < water[i][j]) {
					water[i][j] = max(water[x][y], area[i][j]);
				}
			}
			if (before != water[i][j]) cng = 1;
		}
		if (cng) {
			for (int k = 0; k < 4; ++k) {
				int x = i + loc[k][0];
				int y = j + loc[k][1];
				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				if (!inq[x][y]) {
					inq[x][y] = 1;
					q.push({x, y});
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans += water[i][j] - area[i][j];
		}
	}
	cout << ans;
}
