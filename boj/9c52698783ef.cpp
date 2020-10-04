#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

const int S = 100, F = 101, M = 102;
int c[M][M], f[M][M], w[M][M];
vector<vector<int>> adj;

ii find() {
	int maxFlow = 0, ans = 0;
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

		maxFlow++;
		for (int now = F; now != S; now = p[now]) {
			ans += w[p[now]][now];
			f[p[now]][now] += 1;
			f[now][p[now]] -= 1;
		}
	}

	return ii(maxFlow, ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> in(n), out(n);

	for (int i = 0; i < n; ++i) cin >> in[i];
	for (int i = 0; i < n; ++i) cin >> out[i];

	int t, max_f;
	cin >> t >> max_f;

	adj.resize(M);

	for (int i = 0; i < n; ++i) {
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 50; i < 50 + n; ++i) {
		c[i][F] = 1;
		adj[i].push_back(F);
		adj[F].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (in[i] < out[j]) {
				adj[i].push_back(50 + j);
				adj[50 + j].push_back(i);
				c[i][50 + j] = 1;
				if (out[j] - in[i] < t) {
					int over = t - (out[j] - in[i]);
					w[i][50 + j] = min(over * over, max_f);
					w[50 + j][i] = -w[i][50 + j];
				}
			}
		}
	}

	ii ans = find();

	if (ans.first != n) {
		cout << -1;
		return 0;
	}
	cout << ans.second << ' ';

	for (int i = 0; i < n; ++i) {
		for (int j = 50; j < 50 + n; ++j) {
			w[i][j] *= -1;
			w[j][i] *= -1;
		}
	}
	memset(f, 0, sizeof(f));
	ans = find();
	cout << -ans.second;
}