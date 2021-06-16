#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<int> ans;
int vis[1000];

void dfs(int i) {
	vis[i] = 1;
	for (int u: edge[i]) {
		if (vis[u] == 0) dfs(u);
		else if (vis[u] == 1) {
			cout << 0;
			exit(0);
		}
	}
	ans.push_back(i);
	vis[i] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	edge.resize(n);

	for (int i = 0; i < m; ++i) {
		int sz, a, b;
		cin >> sz;
		for (int j = 0; j < sz; ++j) {
			a = b;
			cin >> b;
			b--;
			if (j) {
				edge[a].push_back(b);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i] == 0) dfs(i);
	}

	for (int i = n - 1; i >= 0; --i) cout << ans[i] + 1 << '\n';
}