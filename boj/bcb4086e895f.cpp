#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while (cin >> n >> m, n || m) {
		vector<vector<ii>> edge(n);
		vector<vector<ii>> edge_rev(n);

		int s, f;
		cin >> s >> f;
		int a, b, w;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> w;
			edge[a].push_back({b, w});
			edge_rev[b].push_back({a, w});
		}

		vector<int> dist(n, INF);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		dist[s] = 0;
		pq.push({0, s});
		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			int d = now.first, u = now.second;
			if (d > dist[u]) continue;
			for (ii e: edge[u]) {
				if (dist[u] + e.second < dist[e.first]) {
					dist[e.first] = dist[u] + e.second;
					pq.push(ii(dist[e.first], e.first));
				}
			}
		}

		for (int i = 0; i < n; ++i) edge[i].clear();

		vector<bool> vis(n, 0);
		queue<int> q;
		q.push(f);
		vis[f] = 1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (ii u: edge_rev[now]) {
				if (dist[u.first] + u.second == dist[now]) {
					if (!vis[u.first]) {
						q.push(u.first);
						vis[u.first] = 1;
					}
				}
				else {
					edge[u.first].push_back({now, u.second});
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				for (ii u: edge_rev[i]) {
					edge[u.first].push_back({i, u.second});
				}
			}
		}

		dist = vector<int>(n, INF);
		dist[s] = 0;
		pq.push({0, s});
		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			int d = now.first, u = now.second;
			if (d > dist[u]) continue;
			for (ii e: edge[u]) {
				if (dist[u] + e.second < dist[e.first]) {
					dist[e.first] = dist[u] + e.second;
					pq.push(ii(dist[e.first], e.first));
				}
			}
		}

		if (dist[f] == INF) cout << -1 << '\n';
		else cout << dist[f] << '\n';
	}
}