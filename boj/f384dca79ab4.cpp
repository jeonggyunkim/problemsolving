#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF (1LL << 60)
using namespace std;

typedef pair<int, int> ii;
typedef tuple<long long, int, int> lii;

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

	vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));
	priority_queue<lii, vector<lii>, greater<lii>> pq;
	pq.push({0, 0, k});
	dist[0][k] = 0;

	while (!pq.empty()) {
		lii now = pq.top(); pq.pop();
		long long d;
		tie(d, a, b) = now;
		if (d > dist[a][b]) continue;
		for (ii e: edge[a]) {
			if (dist[a][b] + e.second < dist[e.first][b]) {
				dist[e.first][b] = dist[a][b] + e.second;
				pq.push({dist[e.first][b], e.first, b});
			}
			if (b && dist[a][b] < dist[e.first][b - 1]) {
				dist[e.first][b - 1] = dist[a][b];
				pq.push({dist[e.first][b - 1], e.first, b - 1});
			}
		}
	}

	long long ans = INF;
	for (int i = 0; i <= k; ++i) {
		ans = min(ans, dist[n - 1][i]);
	}
	cout << ans;
}