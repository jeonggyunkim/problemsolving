#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

typedef pair<int, int> ii;

class SegmentTree {
	private:
		int n;
		vector<int> tree;
		int _find(int l, int r, int i, int li, int ri) {
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return min(_find(l, mid, 2 * i + 1, li, mid), _find(mid + 1, r, 2 * i + 2, mid + 1, ri));
		}
		int _upd(int ind, bool b, int i, int li, int ri) {
			if (li == ri) {
				if (b) return tree[i] = li;
				else return tree[i] = INF;
			}
			int mid = (li + ri) / 2;
			if (ind <= mid) return tree[i] = min(_upd(ind, b, 2 * i + 1, li, mid), tree[2 * i + 2]);
			else return tree[i] = min(_upd(ind, b, 2 * i + 2, mid + 1, ri), tree[2 * i + 1]);
		}
	public:
		SegmentTree(int size) {
			n = size;
			tree.resize(n * 4, INF);
		}
		int find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int ind, bool b) { _upd(ind, b, 0, 0, n - 1); }
};

int n, color_cnt;
vector<vector<int>> edge;
vector<int> super, depth;

vector<ii> color;
vector<int> parent;
vector<vector<int>> node_color, node_num;
vector<SegmentTree> seg;

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
	if (num == 0) {
		parent.push_back(p);
		node_num.push_back(vector<int>());
	}
	node_num[c].push_back(i);
	color[i] = ii(c, num);
	for (int u: edge[i]) {
		if (u != p) {
			if (u == super[i]) make_group(u, i, c, num + 1);
			else make_group(u, i, color_cnt++, 0);
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
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		u--; v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	dfs(0, -1, 0);
	make_group(0, -1, color_cnt++, 0);
	for (int i = 0; i < color_cnt; ++i) seg.push_back(SegmentTree(node_num[i].size()));

	int m;
	cin >> m;
	int op;

	vector<bool> black(n, 0);
	while (m--) {
		cin >> op >> u;
		u--;
		if (op == 1) {
			black[u] = !black[u];
			seg[color[u].first].upd(color[u].second, black[u]);
		}
		else {
			int ans = -1;
			while (color[u].first != 0) {
				int ind = seg[color[u].first].find(0, color[u].second);
				if (ind != INF) ans = node_num[color[u].first][ind];
				u = parent[color[u].first];
			}
			int ind = seg[0].find(0, color[u].second);
			if (ind != INF) ans = node_num[0][ind];
			if (ans == -1) cout << -1 << '\n';
			else cout << ans + 1 << '\n';
		}
	}
}