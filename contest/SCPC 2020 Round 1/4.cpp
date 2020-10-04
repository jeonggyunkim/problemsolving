#include <bits/stdc++.h>
using namespace std;

class SegTree {
	private:
	vector<int> tree;
	int p = 1;
	
	public:
	void upd(int i, int val) {
		i += p;
		tree[i] += val;
		for (i /= 2; i >= 1; i /= 2) {
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}
	}

	int get() {
		return tree[1];
	}

	SegTree(int n) {
		while (p < n) p *= 2;
		tree.resize(2 * p, 0);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int n, k, m;
		cin >> n >> k >> m;

		string s;
		cin >> s;

		vector<tuple<int, bool, int>> arr;
		int now = 0, p = 1;
		for (int i = 0; i < k; ++i) {
			now *= 10;
			now += s[i] - '0';
			p *= 10;
		}
		p /= 10;

		for (int i = 0; i <= n - k; ++i) {
			arr.push_back({now, 1, i});
			if (i != n - k) now = (now % p) * 10 + s[i + k] - '0';
		}

		for (int i = 0; i < n; ++i) {
			char t = s[i];
			s[i] = '1';
			for (int j = max(0, i - k + 1); j <= min(i, n - k); ++j) {
				now = 0;
				for (int ii = 0; ii < k; ++ii) {
					now *= 10;
					now += s[j + ii] - '0';
				}
				arr.push_back({now, 0, i});
			}
			s[i] = t;
		}

		sort(arr.begin(), arr.end());

		int i = 0, j = 0;
		SegTree seg(n);
		int common = 0;
		int ans = -1;
		while (i < arr.size()) {
			int num = get<0>(arr[i]);
			while (j < arr.size() && get<0>(arr[j]) <= num + m) {
				if (get<1>(arr[j])) {
					common++;
					for (int ii = 0; ii < k; ++ii) {
						seg.upd(get<2>(arr[j]) + ii, -1);
					}
				}
				else {
					seg.upd(get<2>(arr[j]), 1);
				}
				j++;
			}

			ans = max(ans, common + max(0, seg.get()));

			while (i < arr.size() && get<0>(arr[i]) == num) {
				if (get<1>(arr[i])) {
					common--;
					for (int ii = 0; ii < k; ++ii) {
						seg.upd(get<2>(arr[i]) + ii, 1);
					}
				}
				else {
					seg.upd(get<2>(arr[i]), -1);
				}
				i++;
			}
		}

		cout << "Case #" << test << '\n';
		cout << ans << '\n';
	}
}