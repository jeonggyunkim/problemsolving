#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

vector<vector<ii>> edge;
int n, p, t;
int place[16];
int dist[16][16];
int dp[16][1 << 16][2];

void dijk(int i) {
	int s = place[i];
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<int> d(n, INF);
	pq.push({0, s});
	d[s] = 0;
	while (!pq.empty()) {
		ii now = pq.top(); pq.pop();
		int dnow = now.first, u = now.second;
		if (d[u] < dnow) continue;
		for (ii e: edge[u]) {
			if (dnow + e.second < d[e.first]) {
				d[e.first] = dnow + e.second;
				pq.push({d[e.first], e.first});
			}
		}
	}

	for (int j = 0; j < p; ++j) {
		dist[i][j] = d[place[j]];
		if (dist[i][j] == INF) {
			cout << "impossible";
			exit(0);
		}
	}
}

int walk(int now, int mask, bool cantaxi) {
	if (mask == 0) {
		if (cantaxi) return min(dist[now][0], t);
		else return dist[now][0];
	}
	if (dp[now][mask][cantaxi] != -1) return dp[now][mask][cantaxi];

	int mini = INF;
	for (int i = 1; i < p; ++i) {
		if (mask & (1 << i)) {
			int loc = walk(i, mask ^ (1 << i), cantaxi);
			mini = min(mini, loc + dist[now][i]);
		}
	}
	if (cantaxi) {
		for (int i = 0; i < p; ++i) {
			if (mask & (1 << i)) {
				int loc = walk(i, mask ^ (1 << i), 0);
				mini = min(mini, loc + t);
			}
		}
	}
	return dp[now][mask][cantaxi] = mini;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, g;
	cin >> n >> p >> m >> g >> t;

	int a, b, w;
	int zero = -1;
	for (int i = 1; i <= p; ++i) {
		cin >> place[i] >> a;
		if (place[i] == 0) zero = i;
		g -= a;
	}
	if (zero != -1) {
		place[zero] = place[p];
		p--;
	}
	p++;

	edge.resize(n);
	while (m--) {
		cin >> a >> b >> w;
		edge[a].push_back({b, w});
		edge[b].push_back({a, w});
	}

	for (int i = 0; i < p; ++i) dijk(i);
	memset(dp, -1, sizeof(dp));
	int ret = walk(0, (1 << p) - 2, 0);
	if (ret <= g) {
		cout << "possible without taxi";
		return 0;
	}
	ret = walk(0, (1 << p) - 2, 1);
	if (ret <= g) cout << "possible with taxi";
	else cout << "impossible";
}