#include <iostream>
#include <vector>
#define N 1000010
using namespace std;

class SegmentTree {
	private:
		int n;
		vector<long long> tree;
		long long build(vector<int>& arr, int i, int li, int ri) {
			if (li == ri) return tree[i] = arr[li];
			int mid = (li + ri) / 2;
			return tree[i] = build(arr, 2 * i + 1, li, mid) + build(arr, 2 * i + 2, mid + 1, ri);
		}
		long long _find(int l, int r, int i, int li, int ri) {
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return _find(l, mid, 2 * i + 1, li, mid) + _find(mid + 1, r, 2 * i + 2, mid + 1, ri);
		}
		void _upd(int ind, int d, int i, int li, int ri) {
			tree[i] += d;
			if (li == ri) return;
			int mid = (li + ri) / 2;
			if (ind <= mid) _upd(ind, d, 2 * i + 1, li, mid);
			else _upd(ind, d, 2 * i + 2, mid + 1, ri);
		}
	public:
		SegmentTree(vector<int>& arr) {
			n = arr.size();
			tree.resize(n * 4);
			build(arr, 0, 0, n - 1);
		}
		long long find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int ind, int d) { return _upd(ind, d, 0, 0, n - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	SegmentTree st(arr);
	int a, b, c;
	while (m || k) {
		cin >> a >> b >> c;
		if (a == 1) {
			m--;
			b--;
			st.upd(b, c - arr[b]);
			arr[b] = c;
		}
		else {
			k--;
			b--; c--;
			cout << st.find(b, c) << '\n';
		}
	}
}