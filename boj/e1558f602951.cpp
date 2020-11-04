#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF (1LL << 60)
#define SQ(n) ((n) * (n))
using namespace std;

typedef pair<long long, int> ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<tuple<int, int, int>>> edge(n);

	int a, b, c, t;
	while (m--) {
		cin >> a >> b >> c >> t;
		a--; b--;
		edge[a].push_back({b, c, t});
		edge[b].push_back({a, c, t});
	}

	int low = 1, high = 100000;
	while (high - low != 1) {
		long long mid = (low + high) / 2;

		vector<long long> dist(n, INF);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		dist[0] = 0;
		pq.push({0, 0});
		while (!pq.empty()) {
			ii now = pq.top(); pq.pop();
			long long d = now.first;
			int u = now.second;
			if (d > dist[u]) continue;
			for (tuple<int, int, int>& e: edge[u]) {
				long long price = mid <= get<2>(e) ? 0 : get<1>(e) * SQ(mid - get<2>(e));
				if (dist[u] + price < dist[get<0>(e)]) {
					dist[get<0>(e)] = dist[u] + price;
					pq.push({dist[get<0>(e)], get<0>(e)});
				}
			}
		}

		if (dist[n - 1] <= k) low = mid;
		else high = mid;
	}
	cout << low;
}