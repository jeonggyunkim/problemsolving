#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<vector<iii>> edge(n);
		int u, v, c, d;
		for (int i = 0; i < k; ++i) {
			cin >> u >> v >> c >> d;
			u--; v--;
			edge[u].push_back(iii(v, c, d));
		}

		vector<vector<int>> dist(n, vector<int>(m + 1, INF));
		queue<ii> q[1001];
		int sz = 0, time = 0;
		dist[0][0] = 0;
		q[0].push({0, 0}); sz++;

		while (sz) {
			queue<ii>& pq = q[time % 1001];
			while (!pq.empty()) {
				ii now = pq.front();
				pq.pop(); sz--;
				u = now.first;
				c = now.second;
				if (time > dist[u][c]) continue;
				for (iii x: edge[u]) {
					int uu = get<0>(x);
					int cc = c + get<1>(x);
					int dd = time + get<2>(x);
					if (cc > m) continue;
					if (dist[uu][cc] > dd) {
						dist[uu][cc] = dd;
						q[dd % 1001].push({uu, cc});
						sz++;
					}
				}
			}
			time++;
		}

		int ans = INF;
		for (int i = 0; i <= m; ++i) {
			ans = min(ans, dist[n - 1][i]);
		}

		if (ans == INF) cout << "Poor KCM\n";
		else cout << ans << '\n';
	}
}