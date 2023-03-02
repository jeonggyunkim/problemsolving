#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;

int dist[10000];
vector<vector<int>> edge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	int n, m, k, a, b;
	cin >> n >> m >> k;
	k--;
	edge.resize(n);

	while (m--) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
	}

	queue<int> q;
	dist[k] = 0;
	q.push(k);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int u: edge[now]) {
			if (u == k) {
				cout << dist[now] + 1;
				return 0;
			}
			if (dist[u] == -1) {
				dist[u] = dist[now] + 1;
				q.push(u);
			}
		}
	}
	cout << -1;
}