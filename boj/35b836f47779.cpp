#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<ii>> edge(n + 2);
	int u, v, w;
	for (int i = 0; i < k; ++i) {
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}

	vector<vector<int>> dist(n + 2, vector<int>(101, INF));
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[0][100] = 0;
	pq.push({0, 100});
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second / 1000, v = now.second % 1000;
		if (d > dist[u][v]) continue;
		for (ii e: edge[u]) {
			if (v >= e.second && dist[u][v] + e.second < dist[e.first][v - e.second]) {
				dist[e.first][v - e.second] = dist[u][v] + e.second;
				pq.push(ii(dist[e.first][v - e.second], e.first * 1000 + v - e.second));
			}
		}
		if (d + 5 < dist[u][100]) {
			dist[u][100] = d + 5;
			pq.push(ii(dist[u][100], u * 1000 + 100));
		}
	}

	int ans = INF;
	for (int i = 0; i <= 100; ++i) {
		ans = min(ans, dist[n + 1][i]);
	}
	cout << ans;
}