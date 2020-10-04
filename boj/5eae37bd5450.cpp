#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<ii>> edge(n);

	int a, b, t;
	while (m--) {
		cin >> a >> b >> t;
		a--; b--;
		edge[a].push_back(ii(b, t));
		edge[b].push_back(ii(a, t));
	}

	vector<int> dist(n, INF);
	dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 0));
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

	vector<int> distk(n, INF);
	while (k--) {
		cin >> a;
		a--;
		distk[a] = 0;
		pq.push(ii(0, a));
	}

	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > distk[u]) continue;
		for (ii e: edge[u]) {
			if (distk[u] + e.second < distk[e.first]) {
				distk[e.first] = distk[u] + e.second;
				pq.push(ii(distk[e.first], e.first));
			}
		}
	}

	vector<int> ans;
	for (int i = 1; i < n; ++i) {
		if (dist[i] < distk[i]) ans.push_back(i + 1);
	}

	if (ans.empty()) cout << 0;
	else for (int u: ans) cout << u << ' ';
}