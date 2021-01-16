#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

class LazyTree {
	private:
		int n;
		vector<int> mn;
		vector<int> mx;
		vector<int> lazy;
		ii build(vector<int>& arr, int i, int li, int ri) {
			if (li == ri) {
				return {mn[i] = arr[li], mx[i] = arr[li]};
			}
			int mid = (li + ri) / 2;
			ii left = build(arr, 2 * i + 1, li, mid);
			ii right = build(arr, 2 * i + 2, mid + 1, ri);
			return {mn[i] = min(left.first, right.first), mx[i] = max(left.second, right.second)};
		}
		ii _find(int l, int r, int i, int li, int ri) {
			if (lazy[i]) {
				if (li != ri) {
					lazy[2 * i + 1] += lazy[i];
					lazy[2 * i + 2] += lazy[i];
				}
				mn[i] += lazy[i];
				mx[i] += lazy[i];
				lazy[i] = 0;
			}
			if (l == li && r == ri) return {mn[i], mx[i]};
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			ii left = _find(l, mid, 2 * i + 1, li, mid);
			ii right = _find(mid + 1, r, 2 * i + 2, mid + 1, ri);
			return {min(left.first, right.first), max(left.second, right.second)};
		}
		ii _upd(int l, int r, int op, int d, int i, int li, int ri) {
			if (lazy[i]) {
				if (li != ri) {
					lazy[2 * i + 1] += lazy[i];
					lazy[2 * i + 2] += lazy[i];
				}
				mn[i] += lazy[i];
				mx[i] += lazy[i];
				lazy[i] = 0;
			}
			if (l == li && r == ri) {
				if (op == 1) {
					lazy[i] += d;
					return {mn[i] + lazy[i], mx[i] + lazy[i]};
				}
				else {
					if (mx[i] - mx[i] / d == mn[i] - mn[i] / d) {
						lazy[i] -= mx[i] - mx[i] / d;
						return {mn[i] + lazy[i], mx[i] + lazy[i]};
					}
				}
			}
			int mid = (li + ri) / 2;
			ii left, right;
			if (r <= mid) {
				left = _upd(l, r, op, d, 2 * i + 1, li, mid);
				right = {mn[2 * i + 2] + lazy[2 * i + 2], mx[2 * i + 2] + lazy[2 * i + 2]};
			}
			else if (l > mid) {
				left = {mn[2 * i + 1] + lazy[2 * i + 1], mx[2 * i + 1] + lazy[2 * i + 1]};
				right = _upd(l, r, op, d, 2 * i + 2, mid + 1, ri);
			}
			else {
				left = _upd(l, mid, op, d, 2 * i + 1, li, mid);
				right = _upd(mid + 1, r, op, d, 2 * i + 2, mid + 1, ri);
			}
			return {mn[i] = min(left.first, right.first), mx[i] = max(left.second, right.second)};
		}
	public:
		LazyTree(vector<int>& arr) {
			n = arr.size();
			mn.resize(n * 4);
			mx.resize(n * 4);
			lazy.resize(n * 4, 0);
			build(arr, 0, 0, n - 1);
		}
		int find(int l, int r) { return _find(l, r, 0, 0, n - 1).second; }
		void upd(int l, int r, int op, int d) { _upd(l, r, op, d, 0, 0, n - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	LazyTree lz(arr);

	while (q--) {
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		if (t == 0) lz.upd(l, r, 1, x);
		else if (t == 1) {
			if (x != 1) lz.upd(l, r, 2, x);
		}
		else cout << lz.find(l, r) << '\n';
	}
}