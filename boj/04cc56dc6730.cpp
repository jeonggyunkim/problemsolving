#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<int> color;
vector<int> cycle, st;
int cnt = 2;

void dfs(int i, int p) {
	if (color[i] == 1) {
		for (int j = st.size() - 1; j >= 0; --j) {
			cycle.push_back(st[j]);
			if (st[j] == i) break;
		}
		return;
	}
	color[i] = 1;
	st.push_back(i);
	for (int u: edge[i]) {
		if (u != p && color[u] != 2) dfs(u, i);
	}
	st.pop_back();
	color[i] = 2;
}

void dfs2(int i) {
	color[i] = cnt;
	for (int u: edge[i]) {
		if (color[u] == 0) {
			dfs2(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	edge.resize(n);
	color.resize(n, 0);

	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(0, -1);
	color = vector<int>(n, 0);
	for (int u: cycle) color[u] = 1;
	for (int u: cycle) {
		dfs2(u);
		cnt++;
	}

	while (q--) {
		cin >> a >> b;
		a--; b--;
		if (color[a] == color[b]) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
}