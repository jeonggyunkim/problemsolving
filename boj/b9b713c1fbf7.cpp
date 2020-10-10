#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<ii>> edge(n);

	int a, b, w;
	while (m--) {
		cin >> a >> b >> w;
		a--; b--;
		edge[a].push_back({b, w});
		edge[b].push_back({a, w});
	}

	vector<int> dist(n, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;

	while (k--) {
		cin >> a;
		a--;
		dist[a] = 0;
		pq.push({0, a});
	}
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
	
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		for (ii u: edge[i]) {
			int d = abs(dist[i] - dist[u.first]);
			ans = max(ans, max(dist[i], dist[u.first]) + (u.second - d + 1) / 2);
		}
	}

	cout << ans;
}