#include <iostream>
#include <vector>
using namespace std;

class LazyTree {
private:
	int n;
	vector<long long> tree;
	vector<long long> lazy;
	long long build(vector<long long>& arr, int i, int li, int ri) {
		if (li == ri) return tree[i] = arr[li];
		int mid = (li + ri) / 2;
		return tree[i] = build(arr, 2 * i + 1, li, mid) + build(arr, 2 * i + 2, mid + 1, ri);
	}
	long long _find(int l, int r, int i, int li, int ri) {
		if (lazy[i]) {
			if (li != ri) {
				lazy[2 * i + 1] += lazy[i];
				lazy[2 * i + 2] += lazy[i];
			}
			tree[i] += lazy[i] * (ri - li + 1);
			lazy[i] = 0;
		}
		if (l == li && r == ri) return tree[i];
		int mid = (li + ri) / 2;
		if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
		if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
		return _find(l, mid, 2 * i + 1, li, mid) + _find(mid + 1, r, 2 * i + 2, mid + 1, ri);
	}
	long long _upd(int l, int r, long long d, int i, int li, int ri) {
		if (l == li && r == ri) {
			lazy[i] += d;
			return tree[i] + lazy[i] * (ri - li + 1);
		}
		int mid = (li + ri) / 2;
		long long left, right;
		if (r <= mid) {
			left = _upd(l, r, d, 2 * i + 1, li, mid);
			right = tree[2 * i + 2] + lazy[2 * i + 2] * (ri - mid);
		}
		else if (l > mid) {
			left = tree[2 * i + 1] + lazy[2 * i + 1] * (mid - li + 1);
			right = _upd(l, r, d, 2 * i + 2, mid + 1, ri);
		}
		else {
			left = _upd(l, mid, d, 2 * i + 1, li, mid);
			right = _upd(mid + 1, r, d, 2 * i + 2, mid + 1, ri);
		}
		tree[i] = left + right;
		return tree[i] + lazy[i] * (ri - li + 1);
	}
public:
	LazyTree(vector<long long>& arr) {
		n = arr.size();
		tree.resize(n * 4, 0);
		lazy.resize(n * 4, 0);
		build(arr, 0, 0, n - 1);
	}
	long long find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
	void upd(int l, int r, long long d) { _upd(l, r, d, 0, 0, n - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	LazyTree lz(arr);

	long long a, b, c, d;
	for (int i = 0; i < m + k; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			b--; c--;
			lz.upd(b, c, d);
		}
		else {
			cin >> b >> c;
			b--; c--;
			cout << lz.find(b, c) << '\n';
		}
	}
}