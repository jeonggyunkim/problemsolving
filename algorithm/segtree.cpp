#include <bits/stdc++.h>
using namespace std;

// Segment Tree
// 세그먼트 트리
class SegTree {
	private:
	vector<long long> tree;
	int p = 1;
	
	public:
	void upd(int i, int val) {
		i += p;
		tree[i] = val;
		for (i /= 2; i >= 1; i /= 2) {
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	}

	long long get(int l, int r) {
		long long ret = 0;
		l += p; r += p;
		while (l <= r) {
			if (l % 2 == 1) ret += tree[l++];
			if (r % 2 == 0) ret += tree[r--];
			l /= 2; r /= 2;
		}
		return ret;
	}

	SegTree(vector<int>& arr) {
		int n = arr.size();
		while (p < n) p *= 2;
		tree.resize(2 * p, 0);

		for (int i = 0; i < n; ++i) tree[p + i] = arr[i];
		for (int i = p - 1; i >= 1; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
};


// Fenwick Tree
// 펜윅 트리
void insert(int i, int d) {
	while (i <= treesz) {
		tree[i] += d;
		i += (i & -i);
	}
}

long long get(int i) {
	long long ret = 0;
	while (i) {
		ret += tree[i];
		i &= (i - 1);
	}
	return ret;
}


// Segment Tree with Lazy Propagation
// 세그먼트 트리 (Lazy)
class LazyTree {
	private:
		int n;
		vector<long long> tree;
		vector<long long> lazy;
		int build(vector<int>& arr, int i, int li, int ri) {
			if (li == ri) return tree[i] = arr[li];
			int mid = (li + ri) / 2;
			return tree[i] = min(build(arr, 2 * i + 1, li, mid), build(arr, 2 * i + 2, mid + 1, ri));
		}
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
		LazyTree(vector<int>& arr) {
			n = arr.size();
			tree.resize(n * 4);
			lazy.resize(n * 4, 0);
			build(arr, 0, 0, n - 1);
		}
		long long find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int l, int r, int d) { _upd(l, r, d, 0, 0, n - 1); }
};