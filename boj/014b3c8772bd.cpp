#include <iostream>
#include <vector>
#include <queue>
#define INF (1LL << 60)
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, int> li;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, f, s, t;
	cin >> n >> m >> f >> s >> t;

	vector<vector<ii>> edge;
	edge.resize(2 * n);

	int a, b, w;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		edge[2 * a].push_back({2 * b, w});
		edge[2 * b].push_back({2 * a, w});
		edge[2 * a + 1].push_back({2 * b + 1, w});
		edge[2 * b + 1].push_back({2 * a + 1, w});
	}

	for (int i = 0; i < f; ++i) {
		cin >> a >> b;
		edge[2 * a].push_back({2 * b + 1, 0});
	}

	priority_queue<li, vector<li>, greater<li>> pq;
	vector<long long> dist(2 * n, INF);
	dist[2 * s] = 0;
	pq.push({0, 2 * s});
	while (!pq.empty()) {
		li now = pq.top(); pq.pop();
		long long d = now.first;
		int u = now.second;
		if (d > dist[u]) continue;
		for (ii v: edge[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				pq.push({dist[v.first], v.first});
			}
		}
	}

	cout << min(dist[2 * t], dist[2 * t + 1]);
}