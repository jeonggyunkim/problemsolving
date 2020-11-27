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
	while (cin >> n >> m) {
		edge = vector<vector<int>>(2 * n + 1, vector<int>());
		vis = vector<int>(2 * n + 1, -1);
		sccId = vector<int>(2 * n + 1, -1);
		vCounter = sCounter = 0;

		int a, b;
		while (m--) {
			cin >> a >> b;
			edge[-a + n].push_back(b + n);
			edge[-b + n].push_back(a + n);
		}
		edge[-1 + n].push_back(1 + n);

		for (int i = 0; i <= 2 * n; ++i) {
			if (i != n && vis[i] == -1) {
				dfs(i);
			}
		}

		bool pos = 1;
		for (int i = 1; i <= n; ++i) {
			if (sccId[i + n] == sccId[-i + n]) {
				pos = 0;
			}
		}
		if (pos) cout << "yes\n";
		else cout << "no\n";
	}
}