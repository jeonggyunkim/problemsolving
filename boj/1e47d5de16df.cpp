#include <iostream>
#include <vector>
#include <queue>
#define INF 1987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<ii>> edge_fox(n);
	vector<vector<ii>> edge_wolf(2 * n);

	int a, b, d;
	while (m--) {
		cin >> a >> b >> d;
		a--; b--;
		edge_fox[a].push_back(ii(b, 2 * d));
		edge_fox[b].push_back(ii(a, 2 * d));
		edge_wolf[a].push_back(ii(b + n, d));
		edge_wolf[a + n].push_back(ii(b, 4 * d));
		edge_wolf[b].push_back(ii(a + n, d));
		edge_wolf[b + n].push_back(ii(a, 4 * d));
	}

	vector<int> dist_fox(n, INF);
	vector<int> dist_wolf(2 * n, INF);

	dist_fox[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, 0));
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist_fox[u]) continue;
		for (ii e: edge_fox[u]) {
			if (dist_fox[u] + e.second < dist_fox[e.first]) {
				dist_fox[e.first] = dist_fox[u] + e.second;
				pq.push(ii(dist_fox[e.first], e.first));
			}
		}
	}

	dist_wolf[0] = 0;
	pq.push(ii(0, 0));
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist_wolf[u]) continue;
		for (ii e: edge_wolf[u]) {
			if (dist_wolf[u] + e.second < dist_wolf[e.first]) {
				dist_wolf[e.first] = dist_wolf[u] + e.second;
				pq.push(ii(dist_wolf[e.first], e.first));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (min(dist_wolf[i], dist_wolf[i + n]) > dist_fox[i]) ans++;
	}

	cout << ans;
}