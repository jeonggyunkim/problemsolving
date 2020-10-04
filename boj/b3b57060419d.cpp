#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> edge;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t;
	cin >> n;
	edge.resize(n);

	for (int i = 0; i < n; ++i) {
		while (1) {
			cin >> t;
			if (t == 0) break;
			t--;
			edge[i].push_back(t);
		}
	}

	vector<int> adj(n, 0);
	vector<int> ans(n, -1);
	vector<bool> inq(n, 0);

	queue<int> q;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		t--;
		ans[t] = 0;
		for (int u: edge[t]) {
			adj[u]++;
			if (!inq[u]) {
				q.push(u);
				inq[u] = 1;
			}
		}
	}

	int time = 1;
	while (!q.empty()) {
		vector<int> to_push;
		vector<int> contam;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			inq[now] = 0;
			if (adj[now] >= (edge[now].size() + 1) / 2) {
				contam.push_back(now);
			}
		}

		for (int u: contam) {
			if (ans[u] != -1) continue;
			ans[u] = time;
			for (int v: edge[u]) {
				adj[v]++;
				if (ans[v] == -1) {
					to_push.push_back(v);
				}
			}
		}

		for (int u: to_push) {
			if (ans[u] == -1 && !inq[u]) {
				inq[u] = 1;
				q.push(u);
			}
		}
		time++;
	}

	for (int u: ans) cout << u << ' ';
}