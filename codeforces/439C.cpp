#include <bits/stdc++.h>
#define N 2552
#define INF 987654321
using namespace std;

int c[N][N], f[N][N], w[N][N];
const int S = N - 2, F = N - 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> low(n, 0), high(n, n - 1);

	int op, l, r, v;
	while (q--) {
		cin >> op >> l >> r >> v;
		l--; r--; v--;
		if (op == 1) for (int i = l; i <= r; ++i) {
			low[i] = max(low[i], v);
		}
		else for (int i = l; i <= r; ++i) {
			high[i] = min(high[i], v);
		}
	}

	for (int i = 0; i < n; ++i) if (low[i] > high[i]) {
		cout << -1;
		return 0;
	}

	vector<int> adj[N];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int node = 50 + 50 * i + j;
			c[node][F] = 1;
			w[node][F] = 1 + 2 * j;
			w[F][node] = -w[node][F];
			adj[node].push_back(F);
			adj[F].push_back(node);
		}
	}

	for (int i = 0; i < n; ++i) {
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = low[i]; j <= high[i]; ++j) {
			for (int k = 0; k < n; ++k) {
				int node = 50 + 50 * j + k;
				c[i][node] = 1;
				adj[i].push_back(node);
				adj[node].push_back(i);
			}
		}
	}

	int ans = 0;
	while (true) {
		vector<int> d(N, INF), p(N, -1);
		vector<bool> in(N, 0);
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

	cout << ans;
}