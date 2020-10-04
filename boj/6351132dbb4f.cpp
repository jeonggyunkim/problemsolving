#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	vector<vector<int>> edge(n + 1);

	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<vector<int>> p(n + 1, vector<int>(16, 0));
	vector<int> d(n + 1, -1);
	queue<int> q;

	p[1][0] = -1;
	d[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int u: edge[t]) {
			if (p[u][0] == 0) {
				p[u][0] = t;
				d[u] = d[t] + 1;
				q.push(u);
			}
		}
	}
	p[1][0] = 0;


	for (int j = 1; j < 16; ++j) {
		for (int i = 1; i <= n; ++i) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}

	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		while (a != b) {
			if (d[a] > d[b]) {
				int j = 0, t = a;
				while (j < 16 && d[p[t][j]] >= d[b]) {
					a = p[t][j];
					j++;
				}
			}
			else if (d[a] < d[b]) {
				int j = 0, t = b;
				while (j < 16 && d[p[t][j]] >= d[a]) {
					b = p[t][j];
					j++;
				}
			}
			else {
				int t1 = a, t2 = b;
				a = p[t1][0]; b = p[t2][0];
				int j = 1;
				while (j < 16 && p[t1][j] != p[t2][j]) {
					a = p[t1][j]; b = p[t2][j];
					j++;
				}
			}
		}
		cout << a << '\n';
	}
}