#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int c[202][202], f[202][202];
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
		cin >> c[i][j];
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	int ans = 0;
	while (true) {
		vector<int> p(202, -1);
		queue<int> q;
		p[S] = S; q.push(S);
		while (!q.empty() && p[F] == -1) {
			int now = q.front(); q.pop();
			for (int u: adj[now]) {
				if (c[now][u] - f[now][u] > 0 && p[u] == -1) {
					p[u] = now;
					q.push(u);
				}
			}
		}

		if (p[F] == -1) break;

		int flow = INF;
		for (int now = F; now != S; now = p[now]) {
			flow = min(flow, c[p[now]][now] - f[p[now]][now]);
		}

		ans += flow;

		for (int now = F; now != S; now = p[now]) {
			f[p[now]][now] += flow;
			f[now][p[now]] -= flow;
		}
	}

	cout << ans;
}