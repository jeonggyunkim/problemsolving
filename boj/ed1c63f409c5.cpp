#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

typedef pair<int, int> ii;

int h[2000], t[2000], e[2000][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, d;
	cin >> n >> r >> d;

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		cin >> h[i] >> t[i] >> e[i][0] >> e[i][1];
	}

	vector<int> dist(n + 1, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[r] = 0;
	pq.push({0, r});
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (int i = 0; i < m; ++i) {
			if (u >= e[i][0] && u + (h[i] - e[i][0]) <= n) {
				int v = u - e[i][0] + e[i][1];
				if (d + t[i] < dist[v]) {
					dist[v] = d + t[i];
					pq.push({dist[v], v});
				}
			}
			if (u >= e[i][1] && u + (h[i] - e[i][1]) <= n) {
				int v = u - e[i][1] + e[i][0];
				if (d + t[i] < dist[v]) {
					dist[v] = d + t[i];
					pq.push({dist[v], v});
				}
			}
		}
	}
	if (dist[d] == INF) cout << -1;
	else cout << dist[d];
}