#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> iii;

int loc[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int tom[100][100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h;
	cin >> m >> n >> h;

	queue<iii> q;
	for (int i = 0; i < h; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < m; ++k) {
		cin >> tom[j][k][i];
		if (tom[j][k][i] == 1) q.push(iii(j, k, i));
	}

	while (!q.empty()) {
		iii t = q.front();
		q.pop();

		for (int k = 0; k < 6; ++k) {
			int y = get<0>(t) + loc[k][0];
			int x = get<1>(t) + loc[k][1];
			int z = get<2>(t) + loc[k][2];
			if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= h) continue;
			if (tom[y][x][z] == 0) {
				tom[y][x][z] = tom[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
				q.push(iii(y, x, z));
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < h; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < m; ++k) {
		if (tom[j][k][i] == 0) {
			cout << -1;
			return 0;
		}
		ans = max(ans, tom[j][k][i]);
	}

	cout << ans - 1;
}