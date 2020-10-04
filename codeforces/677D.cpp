#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int loc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p;
	cin >> n >> m >> p;

	vector<vector<int>> chest(p);
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> d(n, vector<int>(m, INF));

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		int t;
		cin >> t; t--;
		chest[t].push_back(i * m + j);
	}

	for (int i = 0; i < chest[0].size(); ++i) {
		int x = chest[0][i] % m;
		int y = chest[0][i] / m;
		d[y][x] = x + y;
	}

	for (int i = 0; i < p - 1; ++i) {
		int sz1 = chest[i].size();
		int sz2 = chest[i + 1].size();
		if (sz1 * sz2 <= 1000000) {
			for (int j = 0; j < sz1; ++j) {
				int x1 = chest[i][j] % m, y1 = chest[i][j] / m;
				for (int k = 0; k < sz2; ++k) {
					int x2 = chest[i + 1][k] % m, y2 = chest[i + 1][k] / m;
					d[y2][x2] = min(d[y2][x2], d[y1][x1] + abs(x2 - x1) + abs(y2 - y1));
				}
			}
		}
		else {
			vector<ii> toInsert(sz1);
			for (int j = 0; j < sz1; ++j) {
				int x = chest[i][j] % m;
				int y = chest[i][j] / m;
				toInsert[j] = ii(d[y][x], chest[i][j]);
			}
			sort(toInsert.begin(), toInsert.end());

			queue<int> q;
			vector<vector<int>> next(n, vector<int>(m, -1));
			int ind = 0;
			while (ind < sz1 && toInsert[ind].first == toInsert[0].first) {
				next[toInsert[ind].second / m][toInsert[ind].second % m] = toInsert[ind].first;
				q.push(toInsert[ind].second);
				ind++;
			}

			while (!q.empty()) {
				int t = q.front(); q.pop();
				int x = t % m, y = t / m;
				int dist = next[y][x];
				for (int k = 0; k < 4; ++k) {
					int xx = x + loc[k][0];
					int yy = y + loc[k][1];
					if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
					if (next[yy][xx] == -1) {
						next[yy][xx] = dist + 1;
						q.push(yy * m + xx);
					}
				}
				while (ind < sz1 && toInsert[ind].first == dist + 1) {
					x = toInsert[ind].second % m;
					y = toInsert[ind].second / m;
					if (next[y][x] == -1) {
						next[y][x] = dist + 1;
						q.push(toInsert[ind].second);
					}
					ind++;
				}
			}
			for (int j = 0; j < sz2; ++j) {
				int x = chest[i + 1][j] % m;
				int y = chest[i + 1][j] / m;
				d[y][x] = next[y][x];
			}
		}
	}

	cout << d[chest[p - 1][0] / m][chest[p - 1][0] % m];
}