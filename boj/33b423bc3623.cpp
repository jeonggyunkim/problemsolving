#include <iostream>
#include <queue>
#include <vector>
#define INF (1LL << 60)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;

vector<vector<ii>> edge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	edge.resize(n);

	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back({b, i});
		edge[b].push_back({a, i});
	}

	vector<ll> dist(n, INF);
	priority_queue<li, vector<li>, greater<li>> pq;
	dist[0] = 0;
	pq.push({0, 0});

	while (!pq.empty()) {
		li now = pq.top(); pq.pop();
		ll d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii e: edge[u]) {
			ll now = d % m;
			ll base = (d / m) * m, next;
			if (e.second >= now) next = base + e.second + 1;
			else next = base + m + e.second + 1;

			if (next < dist[e.first]) {
				dist[e.first] = next;
				pq.push({next, e.first});
			}
		}
	}
	cout << dist[n - 1];
}