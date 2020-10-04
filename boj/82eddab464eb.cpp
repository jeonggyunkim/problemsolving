#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int c[802][802], f[802][802], w[802][802];
const int S = 800, F = 801;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> adj[802];
	for (int i = 0; i < n; ++i) {
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 400; i < 400 + m; ++i) {
		c[i][F] = 1;
		adj[i].push_back(F);
		adj[F].push_back(i);
	}

	int t, a, b;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		while (t--) {
			cin >> a >> b;
			a += 399;
			w[i][a] = b;
			w[a][i] = -b;
			c[i][a] = 1;
			adj[i].push_back(a);
			adj[a].push_back(i);
		}
	}

	int maxFlow = 0, ans = 0;
	while (true) {
		vector<int> d(802, INF), p(802, -1);
		vector<bool> in(802, 0);
		queue<int> q;
		d[S] = 0; q.push(S);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			in[now] = 0;
			for (int u: adj[now]) {
				if (c[now][u] - f[now][u] > 0 && d[u] > d[now] + w[now][u]) {
					d[u] = d[now] + w[now][u];
					p[u] = now;
					if (!in[u]) {
						q.push(u);
						in[u] = 1;
					}
				}
			}
		}

		if (p[F] == -1) break;

		maxFlow++;
		for (int now = F; now != S; now = p[now]) {
			ans += w[p[now]][now];
			f[p[now]][now] += 1;
			f[now][p[now]] -= 1;
		}
	}

	cout << maxFlow << '\n' << ans;
}