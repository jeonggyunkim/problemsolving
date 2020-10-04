#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int p[260];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	p[a] = b;
}

char s[51][51];
int name[51][51];
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> s[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'S' || s[i][j] == 'K') name[i][j] = cnt++;
		}
	}

	vector<iii> edge;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'S' || s[i][j] == 'K') {
				int a = name[i][j];
				queue<ii> q;
				int d[51][51] = {};
				memset(d, -1, sizeof(d));
				q.push({i, j});
				d[i][j] = 0;
				while (!q.empty()) {
					ii now = q.front();
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int x = now.first + dir[k][0];
						int y = now.second + dir[k][1];
						if (x < 0 || x >= n || y < 0 || y >= n) continue;
						if (d[x][y] == -1 && s[x][y] != '1') {
							q.push({x, y});
							d[x][y] = d[now.first][now.second] + 1;
							if (s[x][y] == 'S' || s[x][y] == 'K') {
								edge.push_back({d[x][y], a, name[x][y]});
							}
						}
					}
				}
			}
		}
	}

	if (edge.size() != m * (m + 1)) {
		cout << -1;
		return 0;
	}

	int ans = 0;
	sort(edge.begin(), edge.end());

	for (int i = 0; i < m + 1; ++i) {
		p[i] = i;
	}

	for (iii& u: edge) {
		int a = find(get<1>(u));
		int b = find(get<2>(u));
		if (a != b) {
			ans += get<0>(u);
			merge(a, b);
		}
	}
	cout << ans;
}