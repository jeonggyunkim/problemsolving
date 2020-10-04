#include <bits/stdc++.h>
using namespace std;
	
typedef pair<int, int> ii;
	
vector<int> lazy;
	
void upd(int l, int r, int d, int i, int li, int ri) {
	if (l == li && r == ri) {
		lazy[i] = max(lazy[i], d);
		return;
	}
	int mid = (li + ri) / 2;
	if (r <= mid) {
		upd(l, r, d, 2 * i + 1, li, mid);
	}
	else if (l > mid) {
		upd(l, r, d, 2 * i + 2, mid + 1, ri);
	}
	else {
		upd(l, mid, d, 2 * i + 1, li, mid);
		upd(mid + 1, r, d, 2 * i + 2, mid + 1, ri);
	}
}
	
int find(int ind, int i, int li, int ri) {
	if (li == ri) {
		int ret = lazy[i];
		lazy[i] = 0;
		return ret;
	}
	if (lazy[i]) {
		lazy[2 * i + 1] = max(lazy[2 * i + 1], lazy[i]);
		lazy[2 * i + 2] = max(lazy[2 * i + 2], lazy[i]);
		lazy[i] = 0;
	}
	int mid = (li + ri) / 2;
	if (ind <= mid) return find(ind, 2 * i + 1, li, mid);
	else return find(ind, 2 * i + 2, mid + 1, ri);
}
	
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	lazy.resize(4 * n, 0);
	
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	int q;
	cin >> q;
	
	int op, a, b;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
			a--;
			find(a, 0, 0, n - 1);
			arr[a] = b;
		}
		else {
			cin >> a;
			upd(0, n - 1, a, 0, 0, n - 1);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		arr[i] = max(arr[i], find(i, 0, 0, n - 1));
		cout << arr[i] << ' ';
	}
}