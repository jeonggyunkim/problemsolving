#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int c[202][202], f[202][202], w[202][202];
const int S = 200, F = 201;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> adj[202];
	for (int i = 100; i < 100 + n; ++i) {
		cin >> c[i][F];
		adj[i].push_back(F);
		adj[F].push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		cin >> c[S][i];
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 0; i < m; ++i) for (int j = 100; j < 100 + n; ++j) {
		cin >> w[i][j];
		w[j][i] = -w[i][j];
		c[i][j] = INF;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	int ans = 0;
	while (true) {
		vector<int> d(202, INF), p(202, -1);
		vector<bool> in(202, 0);
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

		int flow = INF;
		for (int now = F; now != S; now = p[now]) {
			flow = min(flow, c[p[now]][now] - f[p[now]][now]);
		}

		for (int now = F; now != S; now = p[now]) {
			ans += flow * w[p[now]][now];
			f[p[now]][now] += flow;
			f[now][p[now]] -= flow;
		}
	}

	cout << ans;
}