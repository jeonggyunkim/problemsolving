#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define INF 987654321
using namespace std;

typedef pair<long long, long long> ii;

ii arr[500000];
int l[500000], r[500000];

class SegTree {
	private:
	vector<int> tree;
	int p = 1;
	bool mx;
	
	public:
	void upd(int i, int val) {
		i += p;
		tree[i] = val;
		for (i /= 2; i >= 1; i /= 2) {
			if (mx) tree[i] = max(tree[2 * i], tree[2 * i + 1]);
			else tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}

	int get(int l, int r) {
		int ret;
		if (mx) ret = 0;
		else ret = INF;
		l += p; r += p;
		while (l <= r) {
			if (l % 2 == 1) {
				if (mx) ret = max(ret, tree[l++]);
				else ret = min(ret, tree[l++]);
			}
			if (r % 2 == 0) {
				if (mx) ret = max(ret, tree[r--]);
				else ret = min(ret, tree[r--]);
			}
			l /= 2; r /= 2;
		}
		return ret;
	}

	SegTree(int n, bool mx) {
		while (p < n) p *= 2;
		if (mx) tree.resize(2 * p, INF);
		else tree.resize(2 * p, 0);
		this->mx = mx;
	}
};

class LazyTree {
	private:
		int n;
		vector<int> tree;
		vector<int> lazy;
		int _find(int l, int r, int i, int li, int ri) {
			if (lazy[i] != INF) {
				if (li != ri) {
					lazy[2 * i + 1] = min(lazy[2 * i + 1], lazy[i]);
					lazy[2 * i + 2] = min(lazy[2 * i + 2], lazy[i]);
				}
				tree[i] = min(tree[i], lazy[i]);
				lazy[i] = INF;
			}
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return min(_find(l, mid, 2 * i + 1, li, mid), _find(mid + 1, r, 2 * i + 2, mid + 1, ri));
		}
		int _upd(int l, int r, int d, int i, int li, int ri) {
			if (l == li && r == ri) {
				lazy[i] = min(lazy[i], d);
				return min(tree[i], lazy[i]);
			}
			int mid = (li + ri) / 2;
			int left, right;
			if (r <= mid) {
				left = _upd(l, r, d, 2 * i + 1, li, mid);
				right = min(tree[2 * i + 2], lazy[2 * i + 2]);
			}
			else if (l > mid) {
				left = min(tree[2 * i + 1], lazy[2 * i + 1]);
				right = _upd(l, r, d, 2 * i + 2, mid + 1, ri);
			}
			else {
				left = _upd(l, mid, d, 2 * i + 1, li, mid);
				right = _upd(mid + 1, r, d, 2 * i + 2, mid + 1, ri);
			}
			tree[i] = min(left, right);
			return min(tree[i], lazy[i]);
		}
	public:
		LazyTree(int n) {
			this->n = n;
			tree.resize(n * 4, INF);
			lazy.resize(n * 4, INF);
		}
		int find(int l, int r) { return _find(l, r, 0, 0, n - 1); }
		void upd(int l, int r, int d) { _upd(l, r, d, 0, 0, n - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	SegTree lseg(n, 0), rseg(n, 1);

	l[0] = 0;
	lseg.upd(0, 0);
	for (int i = 1; i < n; ++i) {
		int low = -1, high = i;
		while (high - low != 1) {
			int mid = (low + high) / 2;
			if (arr[mid].first < arr[i].first - arr[i].second) low = mid;
			else high = mid;
		}
		if (high == i) l[i] = i;
		else l[i] = lseg.get(high, i - 1);
		lseg.upd(i, l[i]);
	}

	r[n - 1] = n - 1;
	rseg.upd(n - 1, n - 1);
	for (int i = n - 2; i >= 0; --i) {
		int low = i, high = n;
		while (high - low != 1) {
			int mid = (low + high) / 2;
			if (arr[mid].first > arr[i].first + arr[i].second) high = mid;
			else low = mid;
		}
		if (low == i) r[i] = i;
		else r[i] = rseg.get(i + 1, low);
		rseg.upd(i, r[i]);
	}


	LazyTree lz(n);
	lz.upd(0, 0, 1);
	lz.upd(0, r[0], 1);
	for (int i = 1; i < n; ++i) {
		if (l[i] == 0) lz.upd(i, i, 1);
		else {
			lz.upd(i, i, lz.find(l[i] - 1, l[i] - 1) + 1);
		}
		lz.upd(i, r[i], lz.find(i - 1, i - 1) + 1);
	}

	cout << lz.find(n - 1, n - 1);
}