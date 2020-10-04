#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<vector<ii>> edge;
vector<vector<int>> dist;
vector<int> mind;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, t;
	cin >> n >> m >> k;
	edge.resize(n);
	dist.resize(n, vector<int>(n, INF));
	mind.resize(n, INF);

	int s, d;
	cin >> s >> d;
	s--; d--;

	int a, b, w;
	while (m--) {
		cin >> a >> b >> w;
		a--; b--;
		edge[a].push_back({b, w});
		edge[b].push_back({a, w});
	}

	priority_queue<iii, vector<iii>, greater<iii>> pq;
	dist[s][0] = 0;
	mind[s] = 0;
	pq.push({0, 0, s});

	while (!pq.empty()) {
		iii now = pq.top(); pq.pop();
		int cnt = get<0>(now), d = get<1>(now), u = get<2>(now);
		if (d > dist[u][cnt]) continue;
		for (ii e: edge[u]) {
			if (dist[u][cnt] + e.second < mind[e.first]) {
				dist[e.first][cnt + 1] = dist[u][cnt] + e.second;
				mind[e.first] = dist[u][cnt] + e.second;
				pq.push(iii(cnt + 1, dist[e.first][cnt + 1], e.first));
			}
		}
	}

	int tax = 0;
	for (int i = 0; i <= k; ++i) {
		if (i) {
			cin >> t;
			tax += t;
		}
		int ans = INF;
		for (int j = 0; j < n; ++j) {
			if (dist[d][j] != INF) {
				ans = min(ans, dist[d][j] + j * tax);
			}
		}
		cout << ans << '\n';
	}
}