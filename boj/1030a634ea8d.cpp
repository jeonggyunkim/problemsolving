#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> i3;
typedef tuple<int, int, int, int> i4;

vector<int> range;

class LazyTree {
	private:
		int n;
		vector<long long> tree;
		vector<long long> lazy;
		long long _find(int l, int r, int i, int li, int ri) {
			if (lazy[i]) {
				if (li != ri) {
					lazy[2 * i + 1] += lazy[i];
					lazy[2 * i + 2] += lazy[i];
				}
				tree[i] += lazy[i] * (range[ri + 1] - range[li]);
				lazy[i] = 0;
			}
			if (l == li && r == ri) return tree[i];
			int mid = (li + ri) / 2;
			if (r <= mid) return _find(l, r, 2 * i + 1, li, mid);
			if (l >= mid + 1) return _find(l, r, 2 * i + 2, mid + 1, ri);
			return _find(l, mid, 2 * i + 1, li, mid) + _find(mid + 1, r, 2 * i + 2, mid + 1, ri);
		}
		void _upd(int l, int r, int d, int i, int li, int ri) {
			if (l == li && r == ri) {
				lazy[i] += d;
				return;
			}
			tree[i] += (long long)d * (range[r + 1] - range[l]);
			int mid = (li + ri) / 2;
			long long left, right;
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
			tree.resize(n * 4, 0);
			lazy.resize(n * 4, 0);
		}
		long long find(int l, int r) {
			int left = lower_bound(range.begin(), range.end(), l) - range.begin();
			int right = lower_bound(range.begin(), range.end(), r) - range.begin() - 1;
			return _find(left, right, 0, 0, n - 1);
		}
		void upd(int l, int r, int d) {
			int left = lower_bound(range.begin(), range.end(), l) - range.begin();
			int right = lower_bound(range.begin(), range.end(), r) - range.begin() - 1;
			_upd(left, right, d, 0, 0, n - 1);
		}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<i3> q_sum;
	vector<i4> q_ans;
	int op, a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> op >> a >> b >> c;
		if (op == 1) {
			q_sum.push_back({a, b, c});
		}
		else {
			q_ans.push_back({c, a, b, q_ans.size()});
		}
		range.push_back(a);
		range.push_back(b + 1);
	}

	sort(range.begin(), range.end());
	range.erase(unique(range.begin(), range.end()), range.end());
	sort(q_ans.begin(), q_ans.end());

	vector<long long> ans(q_ans.size());

	LazyTree lz(range);
	int ind = 0;
	for (int i = 1; i <= q_sum.size(); ++i) {
		lz.upd(get<0>(q_sum[i - 1]), get<1>(q_sum[i - 1]) + 1, get<2>(q_sum[i - 1]));
		while (ind < q_ans.size() && get<0>(q_ans[ind]) == i) {
			ans[get<3>(q_ans[ind])] = lz.find(get<1>(q_ans[ind]), get<2>(q_ans[ind]) + 1);
			ind++;
		}
	}

	for (long long u: ans) cout << u << '\n';
}