#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int n, color_cnt;
vector<vector<int>> edge;
vector<int> super, depth;

vector<ii> color;
vector<int> parent(1, -1);

int dfs(int i, int p, int d) {
	int cnt = 1;
	depth[i] = d;
	int sup = -1;
	for (int u: edge[i]) {
		if (u != p) {
			int t = dfs(u, i, d + 1);
			cnt += t;
			if (sup < t) {
				sup = t;
				super[i] = u;
			}
		}
	}
	return cnt;
}

void make_group(int i, int p, int c, int num) {
	color[i] = ii(c, num);
	for (int u: edge[i]) {
		if (u != p) {
			if (u == super[i]) make_group(u, i, c, num + 1);
			else {
				parent.push_back(i);
				make_group(u, i, color_cnt++, 0);
			}
		}
	}
}

int lca(int a, int b) {
	if (color[a].first == color[b].first) {
		if (depth[a] < depth[b]) return a;
		else return b;
	}
	else {
		if (depth[a] - color[a].second > depth[b] - color[b].second) {
			return lca(parent[color[a].first], b);
		}
		else {
			return lca(parent[color[b].first], a);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	edge.resize(n);
	super.resize(n);
	depth.resize(n);
	color.resize(n);

	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		u--; v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs(0, -1, 0);
	make_group(0, -1, color_cnt++, 0);

	int m;
	cin >> m;
	while (m--) {
		cin >> u >> v;
		u--; v--;
		cout << lca(u, v) + 1 << '\n';
	}
}