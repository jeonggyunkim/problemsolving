#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int v, m;
		cin >> v >> m;
		
		vector<vector<ii>> edge(v);
		int a, b, c;
		while (m--) {
			cin >> a >> b >> c;
			a--; b--;
			edge[a].push_back(ii(b, c));
			edge[b].push_back(ii(a, c));
		}
		
		vector<bool> used(v, false);
		for (int s = 0; s < v; ++s) {
			vector<int> dist(v, INF);
			vector<vector<int>> before(v);
			dist[s] = 0;
			
			priority_queue<ii, vector<ii>, greater<ii>> pq;
			pq.push(ii(0, s));
			while (!pq.empty()) {
				ii now = pq.top(); pq.pop();
				int d = now.first, u = now.second;
				if (d > dist[u]) continue;
				for (ii vv: edge[u]) {
					if (dist[u] + vv.second < dist[vv.first]) {
						dist[vv.first] = dist[u] + vv.second;
						pq.push(ii(dist[vv.first], vv.first));
						before[vv.first].clear();
						before[vv.first].push_back(u);
					}
					else if (dist[u] + vv.second == dist[vv.first]) before[vv.first].push_back(u);
				}
			}
			
			for (int i = 0; i < v; ++i) for (int u: before[i]) {
				if (u != s) used[u] = 1;
			}
		}
		
		cout << "Case #" << test << '\n';
		vector<int> ans;
		for (int i = 0; i < v; ++i) if (!used[i]) ans.push_back(i + 1);
		cout << ans.size() << ' ';
		for (int i: ans) cout << i << ' ';
		cout << '\n';
	}
}