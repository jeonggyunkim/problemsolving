#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while (cin >> n, n) {
		vis.clear();
		edge.clear();
		sccId.clear();

		vis.resize(n, -1);
		edge.resize(n);
		sccId.resize(n, -1);
		vCounter = sCounter = 0;

		cin >> m;
		int a, b;
		while (m--) {
			cin >> a >> b;
			a--; b--;
			edge[a].push_back(b);
		}

		for (int i = 0; i < n; ++i) {
			if (vis[i] == -1) dfs(i);
		}

		vector<bool> sccleaf(sCounter, 1);
		for (int i = 0; i < n; ++i) {
			if (!sccleaf[sccId[i]]) continue;
			for (int u: edge[i]) {
				if (sccId[i] != sccId[u]) {
					sccleaf[sccId[i]] = 0;
					break;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (sccleaf[sccId[i]]) cout << i + 1 << ' ';
		}
		cout << '\n';
	}
}