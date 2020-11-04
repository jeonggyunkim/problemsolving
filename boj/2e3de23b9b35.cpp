#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

typedef pair<int, int> ii;

vector<vector<ii>> edge;

vector<int> dijkstra(int s) {
	vector<int> dist(edge.size(), INF);
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
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, p1, p2, p3;
	cin >> m >> n >> p1 >> p2 >> p3;
	p1--; p2--; p3--;

	edge.resize(n);
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		a--; b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	vector<int> dist1, dist2, dist3;
	dist1 = dijkstra(p1);
	dist2 = dijkstra(p2);
	dist3 = dijkstra(p3);

	cout << min(dist1[p2] + dist2[p3], dist1[p3] + dist3[p2]);
}