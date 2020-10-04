#include <iostream>
#include <vector>
#include <queue>
#include <float.h>
using namespace std;

typedef pair<int, double> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n >> m;

		vector<vector<ii>> edge(n);
		int a, b;
		double c;
		while (m--) {
			cin >> a >> b >> c;
			edge[a].push_back(ii(b, c));
			edge[b].push_back(ii(a, c));
		}

		vector<double> dist(n, DBL_MAX);
		dist[0] = 1;

		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push(ii(0, 0));
		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			double d = now.first;
			int u = now.second;
			if (d > dist[u]) continue;
			for (ii e : edge[u]) {
				if (dist[u] * e.second < dist[e.first]) {
					dist[e.first] = dist[u] * e.second;
					pq.push(ii(dist[e.first], e.first));
				}
			}
		}

		printf("%.10lf\n", dist[n - 1]);
	}
}
