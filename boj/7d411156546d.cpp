#include <iostream>
#include <vector>
#define INF 1987654321
using namespace std;

typedef pair<int, int> ii;

class SegTree {
	private:
	vector<ii> tree;
	int p = 1;
	
	public:
	void upd(int i, int val) {
		i += p;
		tree[i] = {val, i - p};
		for (i /= 2; i >= 1; i /= 2) {
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}

	ii get(int l, int r) {
		ii ret = {INF, -1};
		l += p; r += p;
		while (l <= r) {
			if (l % 2 == 1) ret = min(ret, tree[l++]);
			if (r % 2 == 0) ret = min(ret, tree[r--]);
			l /= 2; r /= 2;
		}
		return ret;
	}

	SegTree(vector<int>& arr) {
		int n = arr.size();
		while (p < n) p *= 2;
		tree.resize(2 * p, {INF, -1});

		for (int i = 0; i < n; ++i) tree[p + i] = {arr[i], i};
		for (int i = p - 1; i >= 1; --i) {
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	SegTree seg(arr);

	cin >> m;
	int op, a, b;
	while (m--) {
		cin >> op >> a >> b;
		if (op == 1) {
			a--;
			seg.upd(a, b);
		}
		else {
			a--; b--;
			cout << seg.get(a, b).second + 1 << '\n';
		}
	}
}