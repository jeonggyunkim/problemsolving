#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int n, m ,t;

vector<int> dij(vector<vector<ii>>& edge, int s) {
	vector<int> dist(n, INF);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({0, s});
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
	return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n >> m >> t;

		int s, g, h;
		cin >> s >> g >> h;
		s--; g--; h--;
		if (g > h) swap(g, h);

		vector<vector<ii>> edge(n);
		int a, b, w, l;
		while (m--) {
			cin >> a >> b >> w;
			a--; b--;
			if (a > b) swap(a, b);
			if (a == g && b == h) l = w;
			edge[a].push_back({b, w});
			edge[b].push_back({a, w});
		}

		vector<int> goal(t);
		for (int i = 0; i < t; ++i) {
			cin >> goal[i];
			goal[i]--;
		}
		sort(goal.begin(), goal.end());

		vector<int> fromStart = dij(edge, s);
		vector<int> fromG = dij(edge, g);
		vector<int> fromH = dij(edge, h);

		vector<bool> pos(t, 0);
		for (int i = 0; i < t; ++i) {
			int u = goal[i];
			if (fromStart[g] + l + fromH[u] == fromStart[u]) pos[i] = 1;
			if (fromStart[h] + l + fromG[u] == fromStart[u]) pos[i] = 1;
		}
		for (int i = 0; i < t; ++i) {
			if (pos[i]) cout << goal[i] + 1 << ' ';
		}
		cout << '\n';
	}
}