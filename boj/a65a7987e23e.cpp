#include <iostream>
#include <vector>
using namespace std;

class LazyTree {
	private:
		int n;
		vector<int> tree;
		vector<int> lazy;
		int build(vector<int>& arr, int i, int li, int ri) {
			if (li == ri) return tree[i] = arr[li];
			int mid = (li + ri) / 2;
			return tree[i] = build(arr, 2 * i + 1, li, mid) ^ build(arr, 2 * i + 2, mid + 1, ri);
		}
		int _find(int l, int r, int i, int li, int ri) {
			if (lazy[i]) {
				if (li != ri) {
					lazy[2 * i + 1] ^= lazy[i];
					lazy[2 * i + 2] ^= lazy[i];
				}
				if ((ri - li + 1) % 2) tree[i] ^= lazy[i];
				lazy[i] = 0;
			}
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return _find(l, mid, 2 * i + 1, li, mid) ^ _find(mid + 1, r, 2 * i + 2, mid + 1, ri);
		}
		void _upd(int l, int r, int d, int i, int li, int ri) {
			if (l == li && r == ri) {
				lazy[i] ^= d;
				return;
			}
			if ((r - l + 1) % 2) tree[i] ^= d;
			int mid = (li + ri) / 2;
			if (r <= mid) _upd(l, r, d, 2 * i + 1, li, mid);
			else if (l > mid) _upd(l, r, d, 2 * i + 2, mid + 1, ri);
			else {
				_upd(l, mid, d, 2 * i + 1, li, mid);
				_upd(mid + 1, r, d, 2 * i + 2, mid + 1, ri);
			}
		}
	public:
		LazyTree(vector<int>& arr) {
			n = arr.size();
			tree.resize(n * 4);
			lazy.resize(n * 4, 0);
			build(arr, 0, 0, n - 1);
		}
		int find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int l, int r, int d) { _upd(l, r, d, 0, 0, n - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	LazyTree lz(arr);

	int q;
	cin >> q;

	int t, a, b, c;
	while (q--) {
		cin >> t >> a >> b;
		if (a > b) swap(a, b);
		if (t == 1) {
			cin >> c;
			lz.upd(a, b, c);
		}
		else {
			cout << lz.find(a, b) << '\n';
		}
	}
}