#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> edge(n);
	int t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> t;
			if (t) edge[i].push_back(j);
		}
	}

	int ans = -1;

	for (int i = 0; i < n; ++i) {
		vector<int> visited(n, 0);
		queue<int> q;
		q.push(i);
		bool first = 1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			int d;
			if (first) {
				first = 0;
				d = 0;
			}
			else d = visited[now];
			for (int u: edge[now]) {
				if (!visited[u]) {
					visited[u] = d + 1;
					q.push(u);
				}
			}
		}

		for (int j = 0; j < n; ++j) {
			if (!visited[j]) {
				cout << 0;
				return 0;
			}
			ans = max(ans, visited[j]);
		}
	}
	cout << ans;
}