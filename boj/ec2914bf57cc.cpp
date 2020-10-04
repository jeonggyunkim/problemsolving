#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 987654321
using namespace std;

const int S = 2000, F = 2001, M = 2002;
int c[M][M], f[M][M], w[M][M];
vector<vector<int>> adj;

void add_edge(int i, int j, int cap, int wei) {
	c[i][j] = cap;
	adj[i].push_back(j);
	adj[j].push_back(i);
	w[i][j] = wei;
	w[j][i] = -w[i][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	while (cin >> v) {
		cin >> e;
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		memset(w, 0, sizeof(w));

		adj.clear();
		adj.resize(M);

		add_edge(S, 0, 2, 0);
		add_edge(2 * v - 1, F, 2, 0);

		add_edge(0, 1, 2, 0);
		for (int i = 1; i < v - 1; ++i) {
			add_edge(2 * i, 2 * i + 1, 1, 0);
		}
		add_edge(2 * v - 2, 2 * v - 1, 2, 0);

		int ta, tb, tc;
		while (e--) {
			cin >> ta >> tb >> tc;
			ta--; tb--;
			add_edge(ta * 2 + 1, tb * 2, 1, tc);
		}

		int ans = 0;
		while (true) {
			vector<int> d(M, INF), p(M, -1);
			vector<bool> in(M, 0);
			queue<int> q;
			d[S] = 0; q.push(S);
			while (!q.empty()) {
				int now = q.front(); q.pop();
				in[now] = 0;
				for (int u : adj[now]) {
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

			for (int now = F; now != S; now = p[now]) {
				ans += w[p[now]][now];
				f[p[now]][now] += 1;
				f[now][p[now]] -= 1;
			}
		}

		cout << ans << '\n';
	}
}