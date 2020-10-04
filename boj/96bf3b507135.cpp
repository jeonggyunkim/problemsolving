#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;
	s--;

	vector<vector<ii>> edge(n);
	int a, b, w;
	while (m--) {
		cin >> a >> b >> w;
		a--; b--;
		edge[a].push_back({b, w});
	}

	vector<int> dist(n, INF);
	dist[s] = 0;

	priority_queue<ii, vector<ii>, greater<ii>> pq;
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
	
	for (int i = 0; i < n; ++i) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}