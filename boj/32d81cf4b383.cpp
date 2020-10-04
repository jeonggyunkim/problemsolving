#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

class SegmentTree {
	private:
		int n;
		vector<int> tree;
		int build(vector<int>& arr, int i, int li, int ri) {
			if (li == ri) return tree[i] = arr[li];
			int mid = (li + ri) / 2;
			return tree[i] = max(build(arr, 2 * i + 1, li, mid), build(arr, 2 * i + 2, mid + 1, ri));
		}
		int _find(int l, int r, int i, int li, int ri) {
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return max(_find(l, mid, 2 * i + 1, li, mid), _find(mid + 1, r, 2 * i + 2, mid + 1, ri));
		}
		int _upd(int ind, int d, int i, int li, int ri) {
			if (li == ri) return tree[i] = d;
			int mid = (li + ri) / 2;
			if (ind <= mid) return tree[i] = max(_upd(ind, d, 2 * i + 1, li, mid), tree[2 * i + 2]);
			else return tree[i] = max(_upd(ind, d, 2 * i + 2, mid + 1, ri), tree[2 * i + 1]);
		}
	public:
		SegmentTree(vector<int>& arr) {
			n = arr.size();
			tree.resize(n * 4);
			build(arr, 0, 0, n - 1);
		}
		int find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int ind, int d) { _upd(ind, d, 0, 0, n - 1); }
};

int n, color_cnt,dfs_cnt;
vector<vector<iii>> edge;
vector<int> super, depth;

vector<ii> color;
vector<vector<int>> edge_arr(1);
vector<int> parent(1, -1);
vector<ii> edge_ind;
vector<SegmentTree> seg;

int dfs(int i, int p, int d) {
	int cnt = 1;
	depth[i] = d;
	int sup = -1;
	for (iii u: edge[i]) {
		if (get<0>(u) != p) {
			int t = dfs(get<0>(u), i, d + 1);
			cnt += t;
			if (sup < t) {
				sup = t;
				super[i] = get<0>(u);
			}
		}
	}
	return cnt;
}

void make_group(int i, int p, int c, int num, int w) {
	edge_arr[c].push_back(w);
	color[i] = ii(c, num);
	for (iii u: edge[i]) {
		if (get<0>(u) != p) {
			if (get<0>(u) == super[i]) {
				edge_ind[get<2>(u)] = ii(c, num + 1);
				make_group(get<0>(u), i, c, num + 1, get<1>(u));
			}
			else {
				edge_ind[get<2>(u)] = ii(color_cnt, 0);
				edge_arr.push_back(vector<int>());
				parent.push_back(i);
				make_group(get<0>(u), i, color_cnt++, 0, get<1>(u));
			}
		}
	}
}

int query(int a, int b) {
	if (color[a].first == color[b].first) {
		int p = color[a].second;
		int q = color[b].second;
		if (p == q) return -1;
		if (p > q) swap(p, q);
		return seg[color[a].first].find(p + 1, q);
	}
	else {
		if (depth[a] - color[a].second > depth[b] - color[b].second) {
			return max(seg[color[a].first].find(0, color[a].second), query(parent[color[a].first], b));
		}
		else {
			return max(seg[color[b].first].find(0, color[b].second), query(parent[color[b].first], a));
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
	edge_ind.resize(n - 1);

	int u, v, w;
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v >> w;
		u--; v--;
		edge[u].push_back(iii(v, w, i));
		edge[v].push_back(iii(u, w, i));
	}

	dfs(0, -1, 0);
	make_group(0, -1, color_cnt++, 0, -1);
	for (int i = 0; i < color_cnt; ++i) seg.push_back(SegmentTree(edge_arr[i]));

	int m;
	cin >> m;
	int op;
	while (m--) {
		cin >> op >> u >> v;
		if (op == 1) {
			u--;
			seg[edge_ind[u].first].upd(edge_ind[u].second, v);
		}
		else {
			u--; v--;
			if (u == v) cout << 0 << '\n';
			else cout << query(u, v) << '\n';
		}
	}
}