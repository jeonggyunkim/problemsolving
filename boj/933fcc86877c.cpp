#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	vector<vector<ii>> edge(n + 1);

	int a, b, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back(ii(b, c));
		edge[b].push_back(ii(a, c));
	}
	vector<vector<int>> p(n + 1, vector<int>(16, 0));
	vector<int> d(n + 1, -1);
	vector<int> dist(n + 1, -1);
	queue<int> q;

	p[1][0] = -1;
	d[1] = 0;
	dist[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (ii u: edge[t]) {
			if (p[u.first][0] == 0) {
				p[u.first][0] = t;
				d[u.first] = d[t] + 1;
				dist[u.first] = dist[t] + u.second;
				q.push(u.first);
			}
		}
	}
	p[1][0] = 0;


	for (int j = 1; j < 16; ++j) {
		for (int i = 1; i <= n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}

	int ta, tb;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		ta = a; tb = b;
		while (a != b) {
			if (d[a] > d[b]) {
				int j = 0, t = a;
				while (j < 17 && d[p[t][j]] >= d[b]) {
					a = p[t][j];
					j++;
				}
			}
			else if (d[a] < d[b]) {
				int j = 0, t = b;
				while (j < 17 && d[p[t][j]] >= d[a]) {
					b = p[t][j];
					j++;
				}
			}
			else {
				int t1 = a, t2 = b;
				a = p[t1][0]; b = p[t2][0];
				int j = 1;
				while (j < 17 && p[t1][j] != p[t2][j]) {
					a = p[t1][j]; b = p[t2][j];
					j++;
				}
			}
		}
		cout << dist[ta] + dist[tb] - 2 * dist[a] << '\n';
	}
}