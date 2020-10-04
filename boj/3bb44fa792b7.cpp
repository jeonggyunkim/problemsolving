#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long, long long> ii;

vector<long long> tree;
vector<ii> lazy;

long long find(int ind, int i, int li, int ri) {
	if (lazy[i].first || lazy[i].second) {
		if (li != ri) {
			lazy[2 * i + 1].first += lazy[i].first;
			lazy[2 * i + 1].second += lazy[i].second;
			lazy[2 * i + 2].first += lazy[i].first + ((ri - li + 2) / 2) * lazy[i].second;
			lazy[2 * i + 2].second += lazy[i].second;
		}
		else tree[li] += lazy[i].first;
		lazy[i] = {0, 0};
	}
	if (li == ri) return tree[li];
	int mid = (li + ri) / 2;
	if (ind <= mid) return find(ind, 2 * i + 1, li, mid);
	else return find(ind, 2 * i + 2, mid + 1, ri);
}

void upd(int l, int r, long long a, long long b, int i, int li, int ri) {
	if (l == li && r == ri) {
		lazy[i].first += a;
		lazy[i].second += b;
		return;
	}
	if (li == ri) return;
	int mid = (li + ri) / 2;
	if (r <= mid) upd(l, r, a, b, 2 * i + 1, li, mid);
	else if (l > mid) upd(l, r, a, b, 2 * i + 2, mid + 1, ri);
	else {
		upd(l, mid, a, b, 2 * i + 1, li, mid);
		upd(mid + 1, r, a + (mid - l + 1) * b, b, 2 * i + 2, mid + 1, ri);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	tree.resize(n);
	lazy.resize(n * 4, {0, 0});

	for (int i = 0; i < n; ++i) cin >> tree[i];

	int q;
	cin >> q;
	int op, l, r, x;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r;
			l--; r--;
			upd(l, r, 1, 1, 0, 0, n - 1);
		}
		else {
			cin >> x;
			x--;
			cout << find(x, 0, 0, n - 1) << '\n';
		}
	}
}