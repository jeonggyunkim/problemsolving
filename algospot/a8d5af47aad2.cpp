#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		map<int, int> m;
		int a, b;
		while (n--) {
			cin >> a >> b;
			if (m.count(a - b)) m[a - b] = min(a, m[a - b]);
			else m[a - b] = a;
		}

		vector<int> dist(400, INF);
		priority_queue<ii, vector<ii>, greater<ii>> pq;

		dist[200] = 0;
		pq.push(ii(0, 200));

		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			int d = now.first, u = now.second;
			if (u == 0) break;
			if (d > dist[u]) continue;
			for (auto it = m.begin(); it != m.end(); ++it) {
				int t = u + it->first;
				if (t > 0 && t < 400) {
					if (t == 200) t = 0;
					if (dist[u] + it->second < dist[t]) {
						dist[t] = dist[u] + it->second;
						pq.push(ii(dist[t], t));
					}
				}
			}
		}

		if (dist[0] == INF) cout << "IMPOSSIBLE\n";
		else cout << dist[0] << '\n';
	}
}
