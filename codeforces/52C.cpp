#include <bits/stdc++.h>
using namespace std;

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

	char input[100];
	cin.getline(input, 100);
	while (q--) {
		cin.getline(input, 100);
		int in[3] = {};
		bool start = 1, neg = 0;
		int pos = -1;
		for (int i = 0; input[i]; ++i) {
			if (start) {
				pos++;
				start = 0;
			}
			if (input[i] == ' ') start = 1;
			else if (input[i] == '-') neg = 1;
			else {
				in[pos] *= 10;
				if (neg) in[pos] -= input[i] - '0';
				else in[pos] += input[i] - '0';
			}
		}

		int l = in[0], r = in[1], d = in[2];
		if (pos == 2) {
			if (r >= l)	lz.upd(l, r, d);
			else {
				lz.upd(l, n - 1, d);
				lz.upd(0, r, d);
			}
		}
		else {
			if (r >= l)	cout << lz.find(l, r) << '\n';
			else cout << min(lz.find(l, n - 1), lz.find(0, r)) << '\n';
		}
	}
}