#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

class LazyTree {
	private:
		int n;
		vector<long long> tree;
		vector<long long> lazy;
		long long _find(int l, int r, int i, int li, int ri) {
			if (lazy[i]) {
				if (li != ri) {
					lazy[2 * i + 1] += lazy[i];
					lazy[2 * i + 2] += lazy[i];
				}
				tree[i] += lazy[i];
				lazy[i] = 0;
			}
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return min(_find(l, mid, 2 * i + 1, li, mid), _find(mid + 1, r, 2 * i + 2, mid + 1, ri));
		}
		long long _upd(int l, int r, int d, int i, int li, int ri) {
			if (l == li && r == ri) {
				lazy[i] += d;
				return tree[i] + lazy[i];
			}
			int mid = (li + ri) / 2;
			long long left, right;
			if (r <= mid) {
				left = _upd(l, r, d, 2 * i + 1, li, mid);
				right = tree[2 * i + 2] + lazy[2 * i + 2];
			}
			else if (l > mid) {
				left = tree[2 * i + 1] + lazy[2 * i + 1];
				right = _upd(l, r, d, 2 * i + 2, mid + 1, ri);
			}
			else {
				left = _upd(l, mid, d, 2 * i + 1, li, mid);
				right = _upd(mid + 1, r, d, 2 * i + 2, mid + 1, ri);
			}
			tree[i] = min(left, right);
			return tree[i] + lazy[i];
		}
	public:
		LazyTree(int i) {
			n = i;
			tree.resize(n * 4, 0);
			lazy.resize(n * 4, 0);
		}
		long long find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int l, int r, int d) { _upd(l, r, d, 0, 0, n - 1); }
};

int n;
vector<ii> index;
int cnt = 0;
vector<vector<int>> child;

void dfs(int i) {
	index[i].first = cnt;
	for (int u: child[i]) {
		dfs(u);
	}
	index[i].second = cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q, t;
	cin >> n >> q;
	index.resize(n);
	child.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t != -1) {
			t--;
			child[t].push_back(i);
		}
	}
	dfs(0);

	LazyTree lz(n);
	int op, a, b;
	while (q--) {
		cin >> op >> a;
		a--;
		if (op == 1) {
			cin >> b;
			lz.upd(index[a].first, index[a].second, b);
		}
		else {
			cout << lz.find(index[a].second, index[a].second) << '\n';
		}
	}
}