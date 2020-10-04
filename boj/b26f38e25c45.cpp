#include <iostream>
#include <vector>
using namespace std;

class SegTree {
	private:
	vector<long long> tree;
	int p = 1;
	
	public:
	void upd(int i, int d) {
		i += p;
		tree[i] += d;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> odd(n / 2), even((n + 1) / 2);
	for (int i = 0; i < n; ++i) {
		if (i & 1) cin >> odd[i / 2];
		else cin >> even[i / 2];
	}

	SegTree od(odd), ev(even);

	int a, b, c;
	while (q--) {
		cin >> a >> b >> c;
		b--;
		if (a == 1) {
			c--;
			long long o = c == 0 ? 0 : od.get(b / 2, (c - 1) / 2);
			long long e = ev.get((b + 1) / 2, c / 2);
			cout << abs(o - e) << '\n';
		}
		else {
			if (b & 1) od.upd(b / 2, c);
			else ev.upd(b / 2, c);
		}
	}
}