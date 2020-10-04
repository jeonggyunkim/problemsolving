#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char input[101][101];
	int name[101][101];
	memset(name, -1, sizeof(name));
	for (int i = 0; i < n; ++i) cin >> input[i];

	int s, f;
	int cnt = 0;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (input[i][j] != '#') {
			name[i][j] = cnt;
			if (input[i][j] == 'K') {
				s = cnt;
				for (int k = 0; k < 4; ++k) {
					int x = i + dir[k][0], y = j + dir[k][1];
					if (x < 0 || x >= n || y < 0 || y >= m) continue;
					if (input[x][y] == 'H') {
						cout << -1;
						return 0;
					}
				}
			}
			if (input[i][j] == 'H') f = cnt;
			cnt++;
		}
	}

	vector<map<int, int>> capacity(2 * cnt);
	vector<map<int, int>> flow(2 * cnt);

	for (int i = 0; i < cnt; ++i) {
		if (i == s || i == f) capacity[i][i + cnt] = 987654321;
		else capacity[i][i + cnt] = 1;
		capacity[i + cnt][i] = 0;
		flow[i][i + cnt] = 0;
		flow[i + cnt][i] = 0;
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (name[i][j] != -1) {
			for (int k = 0; k < 4; ++k) {
				int x = i + dir[k][0], y = j + dir[k][1];
				if (x < 0 || x >= n || y < 0 || y >= m || name[x][y] == -1) continue;
				int xx = cnt + name[i][j], yy = name[x][y];
				capacity[xx][yy] = 1;
				capacity[yy][xx] = 0;
				flow[xx][yy] = 0;
				flow[yy][xx] = 0;
			}
		}
	}

	int totalFlow = 0;
	while (true) {
		vector<int> p(cnt * 2, -1);
		queue<int> q;
		p[s] = 0;
		q.push(s);

		while (!q.empty() && p[f] == -1) {
			int now = q.front(); q.pop();
			for (auto it = capacity[now].begin(); it != capacity[now].end(); ++it) {
				int i = it->first;
				if (p[i] == -1 && capacity[now][i] - flow[now][i] > 0) {
					q.push(i);
					p[i] = now;
				}
			}
		}

		if (p[f] == -1) break;

		for (int i = f; i != 0; i = p[i]) {
			flow[p[i]][i]++;
			flow[i][p[i]]--;
		}
		totalFlow += 1;
	}

	cout << totalFlow;
}