#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

const int S = 22, F = 23, M = 24;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int c[M][M] = {}, f[M][M] = {}, w[M][M] = {};
		vector<int> adj[M];
		for (int i = 0; i < 11; ++i) {
			c[S][i] = 1;
			adj[S].push_back(i);
			adj[i].push_back(S);
		}

		for (int i = 11; i < 22; ++i) {
			c[i][F] = 1;
			adj[i].push_back(F);
			adj[F].push_back(i);
		}

		for (int i = 0; i < 11; ++i) for (int j = 11; j < 22; ++j) {
			cin >> w[j][i];
			if (w[j][i] != 0) {
				w[i][j] = -w[j][i];
				c[i][j] = 1;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
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

			for (int now = F; now != S; now = p[now]) {
				ans += w[p[now]][now];
				f[p[now]][now] += 1;
				f[now][p[now]] -= 1;
			}
		}

		cout << -ans << '\n';
	}
}