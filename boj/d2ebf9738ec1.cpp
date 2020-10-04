#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r;
	cin >> n >> r;

	vector<vector<ii>> edge(n);
	while (r--) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		a--; b--;
		edge[a].push_back(ii(b, c + d * max(0, e - 10)));
	}

	vector<int> dist(n, INF);
	vector<int> gj(n, 0);
	dist[0] = 0;
	gj[0] = 1;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 0));
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii e : edge[u]) {
			if (dist[u] + e.second < dist[e.first]) {
				dist[e.first] = dist[u] + e.second;
				gj[e.first] = gj[u] + 1;
				pq.push(ii(dist[e.first], e.first));
			}
			else if (dist[u] + e.second == dist[e.first]) {
				gj[e.first] = min(gj[e.first], gj[u] + 1);
			}
		}
	}

	if (dist[n - 1] == INF) cout << "It is not a great way.";
	else cout << dist[n - 1] << ' ' << gj[n - 1];
}