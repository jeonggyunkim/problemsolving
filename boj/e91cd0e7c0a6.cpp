#include <iostream>
#include <queue>
#define MOD 1000000009
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, s, e;
	cin >> n >> m >> s >> e;
	s--; e--;

	vector<vector<ii>> edge(n);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		a--; b--;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}

	vector<ll> dist(n, (1LL << 60));
	vector<ll> cnt(n, 1LL << 60);
	priority_queue<li, vector<li>, greater<li>> pq;
	dist[s] = 0;
	cnt[s] = 1;
	pq.push({0, s});
	while (!pq.empty()) {
		li now = pq.top(); pq.pop();
		ll d = now.first;
		int u = now.second;
		if (d > dist[u]) continue;
		for (ii e: edge[u]) {
			if (dist[u] + e.second < dist[e.first]) {
				dist[e.first] = dist[u] + e.second;
				cnt[e.first] = cnt[u];
				pq.push({dist[e.first], e.first});
			}
			else if (dist[u] + e.second == dist[e.first]) {
				(cnt[e.first] += cnt[u]) %= MOD;
			}
		}
	}
	cout << cnt[e];
}