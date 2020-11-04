#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

class SegTree {
	private:
	vector<int> tree;
	int p = 1;
	
	public:
	void upd(int i, int val) {
		i += p;
		tree[i] = val;
		for (i /= 2; i >= 1; i /= 2) {
			tree[i] = min(tree[2 * i], tree[2 * i + 1]);
		}
	}

	int get(int l, int r) {
		int ret = INF;
		l += p; r += p;
		while (l <= r) {
			if (l % 2 == 1) ret = min(ret, tree[l++]);
			if (r % 2 == 0) ret = min(ret, tree[r--]);
			l /= 2; r /= 2;
		}
		return ret;
	}

	SegTree(vector<int>& arr) {
		int n = arr.size();
		while (p < n) p *= 2;
		tree.resize(2 * p, INF);

		for (int i = 0; i < n; ++i) tree[p + i] = arr[i];
		for (int i = p - 1; i >= 1; --i) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<int> arr(s.size() + 1);
	arr[0] = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') arr[i + 1] = arr[i] + 1;
		else arr[i + 1] = arr[i] - 1;
	}

	SegTree seg(arr);

	int q;
	cin >> q;

	int a, b, ans = 0;
	while (q--) {
		cin >> a >> b;
		a--;
		if (arr[a] == arr[b] && seg.get(a, b) >= arr[a]) {
			ans++;
		}
	}
	cout << ans;
}