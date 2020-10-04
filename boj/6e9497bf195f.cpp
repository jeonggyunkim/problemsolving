#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<vector<int>> Mtree;

void build(int ind, int l, int r) {
	Mtree[ind] = vector<int>(r - l + 1);
	for (int i = l; i <= r; ++i) {
		Mtree[ind][i - l] = arr[i];
	}
	sort(Mtree[ind].begin(), Mtree[ind].end());
	if (l == r) return;
	else {
		int mid = (l + r) / 2;
		build(ind * 2 + 1, l, mid);
		build(ind * 2 + 2, mid + 1, r);
	}
}

int find(int l, int r, int num, int i, int li, int ri) {
	if (l == li && r == ri) {
		auto it = upper_bound(Mtree[i].begin(), Mtree[i].end(), num);
		return it - Mtree[i].begin();
	}
	int mid = (li + ri) / 2;
	if (r <= mid) return find(l, r, num, 2 * i + 1, li, mid);
	else if (l > mid) return find(l, r, num, 2 * i + 2, mid + 1, ri);
	else {
		return find(l, mid, num, 2 * i + 1, li, mid) + find(mid + 1, r, num, 2 * i + 2, mid + 1, ri);
	}
}

int query(int i, int j, int k) {
	int low = -1e9 - 10, high = 1e9 + 10;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		int cnt = find(i, j, mid, 0, 0, n - 1);
		if (cnt < k) low = mid;
		else high = mid;
	}
	return high;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;

	arr.resize(n);
	Mtree.resize(4 * n);

	for (int i = 0; i < n; ++i) cin >> arr[i];
	build(0, 0, n - 1);

	int i, j, k;
	while (q--) {
		cin >> i >> j >> k;
		i--; j--;
		cout << query(i, j, k) << '\n';
	}
}