#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#define INF (1LL << 60)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int n, score[5000];
int ind[2000][2000];
vector<vector<ii>> edge;
vector<vector<int>> child;
int p[2000];

int dfs(int i) {
	int cnt = 1;
	for (int u: child[i]) {
		cnt += dfs(u);
	}
	if (p[i] != -1) score[ind[p[i]][i]] += cnt;
	return cnt;
}

void dijkstra(int s) {
	vector<ll> dist(n, INF);
	memset(p, -1, sizeof(p));
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[s] = 0;
	p[s] = -1;
	pq.push({0, s});
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		ll d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii e: edge[u]) {
			if (dist[u] + e.second < dist[e.first]) {
				dist[e.first] = dist[u] + e.second;
				p[e.first] = u;
				pq.push({dist[e.first], e.first});
			}
		}
	}
	for (int i = 0; i < n; ++i) child[i].clear();
	for (int i = 0; i < n; ++i) {
		if (p[i] != -1) child[p[i]].push_back(i);
	}
	dfs(s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;
	edge.resize(n);
	child.resize(n);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		ind[a][b] = i;
		edge[a].push_back({b, c});
	}

	for (int i = 0; i < n; ++i) dijkstra(i);
	int mx = -1, cnt = 0;
	for (int i = 0; i < m; ++i) {
		if (score[i] > mx) {
			mx = score[i];
			cnt = 1;
		}
		else if (score[i] == mx) cnt++;
	}
	cout << cnt << '\n';
	for (int i = 0; i < m; ++i) {
		if (score[i] == mx) cout << i + 1 << ' ';
	}
}