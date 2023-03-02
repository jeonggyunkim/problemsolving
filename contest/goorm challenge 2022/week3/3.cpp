#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, a, b;
	cin >> n >> m >> k;

	vector<vector<int>> edge(n);
	vector<int> dist(n, -1);
	queue<int> q;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dist[0] = 0;
	q.push(0);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int u: edge[now]) {
			if (dist[u] == -1) {
				dist[u] =dist[now] + 1;
				q.push(u);
			}
		}
	}
	if (dist[n - 1] == -1 || dist[n - 1] > k) cout << "NO";
	else cout << "YES";
}