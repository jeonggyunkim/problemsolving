#include <iostream>
#include <vector>
#include <queue>
#define INF (1LL << 61)
using namespace std;

typedef pair<long long, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> visi(n);
	for (int i = 0; i < n; ++i) cin >> visi[i];
	
	vector<vector<ii>> edge(n);
	int a, b, t;
	while (m--) {
		cin >> a >> b >> t;
		edge[a].push_back({b, t});
		edge[b].push_back({a, t});
	}

	vector<long long> dist(n, INF);
	dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		long long d = now.first;
		int u = now.second;
		if (d > dist[u]) continue;
		for (ii e: edge[u]) {
			if ((visi[e.first] == 0 || e.first == n - 1) && dist[u] + e.second < dist[e.first]) {
				dist[e.first] = dist[u] + e.second;
				pq.push(ii(dist[e.first], e.first));
			}
		}
	}

	if (dist[n - 1] == INF) cout << -1;
	else cout << dist[n - 1];
}