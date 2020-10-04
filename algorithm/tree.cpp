#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

// DFS with finding depth, super
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

// HLD (need super)
void make_group(int i, int p, int c, int num) {
	if (num == 0) parent.push_back(p);
	color[i] = ii(c, num);
	for (int u: edge[i]) {
		if (u != p) {
			if (u == super[i]) make_group(u, i, c, num + 1);
			else make_group(u, i, color_cnt++, 0);
		}
	}
}

// LCA (need depth, color, parent of color)
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

// LCA (sparse table)
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int inc = depth[a] - depth[b];
	for (int i = 0; i < 18; ++i) {
		if (inc & (1 << i)) a = parent[a][i];
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; --i) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}