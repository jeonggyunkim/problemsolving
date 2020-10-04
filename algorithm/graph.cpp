#include <bits/stdc++.h>
#define INF 987654231
using namespace std;

typedef pair<int, int> ii;

// Dijkstra Algorithm
// 다익스트라 알고리즘
int n, s, f;
vector<vector<ii>> edge(n);
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

// Floyd-Warshall Algorithm
// 플로이드 와샬 알고리즘
int n, m;
vector<vector<int>> dist(n, vector<int>(n, INF));
for (int i = 0; i < n; ++i) dist[i][i] = 0;

int a, b, w;
while (m--) {
	cin >> a >> b >> w;
	a--; b--;
	dist[a][b] = w;
	dist[b][a] = w;
}

for (int k = 0; k < n; ++k) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
}


// Bellman-Ford Algorithm
// 벨만 포드 알고리즘
for (int i = 1; i <= n - 1; ++i) {
	for (int j = 0; j < m; ++j) {
		tie(a, b, w) = edge[j];
		if (dist[a] == INF) continue;
		int t = dist[a] + w;
		if (dist[b] > t) dist[b] = t;
	}
}

for (int i = 0; i < m; ++i) {
	tie(a, b, w) = edge[i];
	if (dist[a] != INF && dist[b] > dist[a] + w) {
		cout << "Negative";
		return 0;
	}
}


// SCC
// sccId는 위상정렬의 역순
vector<vector<int>> edge;
vector<int> vis, sccId;
stack<int> s;
int vCounter, sCounter;

int dfs(int n) {
	int ret = vis[n] = vCounter++;
	s.push(n);

	for (int u: edge[n]) {
		if (vis[u] == -1) {
			int r = dfs(u);
			ret = min(ret, r);
		}
		else if (vis[u] < vis[n] && sccId[u] == -1) ret = min(ret, vis[u]);
	}

	if (ret == vis[n]) {
		while (1) {
			int t = s.top(); s.pop();
			sccId[t] = sCounter;
			if (t == n) break;
		}
		sCounter++;
	}
	return ret;
}
