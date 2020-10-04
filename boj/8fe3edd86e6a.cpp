#include <iostream>
using namespace std;

int stree[300010];
bool lazy[300010];

int find(int l, int r, int li, int ri, int i) {
	if (lazy[i]) {
		if (li != ri) {
			lazy[2 * i + 1] ^= lazy[i];
			lazy[2 * i + 2] ^= lazy[i];
		}
		stree[i] = (ri - li + 1) - stree[i];
		lazy[i] = 0;
	}
	if (l == li && r == ri) return stree[i];
	int mid = (li + ri) / 2;
	if (r <= mid) return find(l, r, li, mid, 2 * i + 1);
	if (l >= mid + 1) return find(l, r, mid + 1, ri, 2 * i + 2);
	return find(l, mid, li, mid, 2 * i + 1) + find(mid + 1, r, mid + 1, ri, 2 * i + 2);
}

void set(int l, int r, int li, int ri, int i) {
	if (l == li && r == ri) {
		lazy[i] ^= true;
		return;
	}
	stree[i] += (r - l + 1) - 2 * find(l, r, li, ri, i);
	int mid = (li + ri) / 2;
	if (r <= mid) set(l, r, li, mid, 2 * i + 1);
	else if (l >= mid + 1) set(l, r, mid + 1, ri, 2 * i + 2);
	else {
		set(l, mid, li, mid, 2 * i + 1);
		set(mid + 1, r, mid + 1, ri, 2 * i + 2);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		b--; c--;
		if (a == 0) set(b, c, 0, n - 1, 0);
		else cout << find(b, c, 0, n - 1, 0) << '\n';
	}
}