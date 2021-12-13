#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> i3;

long long val[5010];
long long D[5010][5010];

inline long long C(int i, int j) {
	return (j - i) * (val[j] - val[i - 1]);
}

void f(int t, int s, int e, int l, int r) {
	if (s > e) return;
	int m = (s + e) / 2;
	int p;
	D[t][m] = (1LL << 60);
	for (int i = l; i <= min(m - 1, r); ++i) {
		long long now = D[t - 1][i] + C(i + 1, m);
		if (now < D[t][m]) {
			p = i;
			D[t][m] = now;
		}
	}
	f(t, s, m - 1, l, p);
	f(t, m + 1, e, p, r);
}

vector<vector<ii>> adj;
vector<i3> edge;

void dijkstra(vector<int>& dist, int s) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int d = now.first, u = now.second;
		if (d > dist[u]) continue;
		for (ii e: adj[u]) {
			if (dist[u] + e.second < dist[e.first]) {
				dist[e.first] = dist[u] + e.second;
				pq.push(ii(dist[e.first], e.first));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b, s, r;
	cin >> n >> b >> s >> r;
	adj.resize(n);

	for (int i = 0; i < r; ++i) {
		int u, v, l;
		cin >> u >> v >> l;
		u--; v--;
		edge.push_back({{u, v}, l});
	}

	vector<int> from(n, INF), to(n, INF);
	for (int i = 0; i < r; ++i) {
		adj[edge[i].first.first].push_back({edge[i].first.second, edge[i].second});
	}
	dijkstra(from, b);
	for (int i = 0; i < n; ++i) adj[i].clear();
	for (int i = 0; i < r; ++i) {
		adj[edge[i].first.second].push_back({edge[i].first.first, edge[i].second});
	}
	dijkstra(to, b);

	for (int i = 1; i <= b; ++i) val[i] = from[i - 1] + to[i - 1];
	sort(val + 1, val + b + 1);
	for (int i = 1; i <= b; ++i) val[i] += val[i - 1];

	for (int i = 1; i <= b; ++i) D[1][i] = val[i] * (i - 1);
	for (int i = 2; i <= s; ++i) {
		f(i, i, b, 1, b);
	}
	cout << D[s][b];
}