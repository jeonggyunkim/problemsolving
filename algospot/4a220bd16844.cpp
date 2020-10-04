#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int v, e, n, m;
		cin >> v >> e >> n >> m;

		vector<vector<ii>> edge(v + 1);

		int a, b, c;
		while (e--) {
			cin >> a >> b >> c;
			edge[a].push_back(ii(b, c));
			edge[b].push_back(ii(a, c));
		}

		vector<int> fire(n);
		for (int i = 0; i < n; ++i) cin >> fire[i];

		vector<int> dist(v + 1, 987654321);
		priority_queue<ii, vector<ii>, greater<ii>> pq;

		for (int i = 0; i < m; ++i) {
			cin >> a;
			dist[a] = 0;
			pq.push(ii(0, a));
		}

		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			int d = now.first, u = now.second;
			if (d > dist[u]) continue;
			for (ii e : edge[u]) {
				if (dist[u] + e.second < dist[e.first]) {
					dist[e.first] = dist[u] + e.second;
					pq.push(ii(dist[e.first], e.first));
				}
			}
		}

		long long ans = 0;
		for (int i: fire) ans += dist[i];

		cout << ans << '\n';
	}
}
