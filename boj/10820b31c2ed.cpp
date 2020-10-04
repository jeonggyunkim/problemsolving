#include <iostream>
using namespace std;

int input[1000010];
long long stree[2100010];
long long lazy[2100010];

long long build(int li, int ri, int i) {
	if (li == ri) return stree[i] = input[li];
	long long i1 = build(li, (li + ri) / 2, 2 * i + 1);
	long long i2 = build((li + ri) / 2 + 1, ri, 2 * i + 2);
	return stree[i] = i1 + i2;
}

long long find(int l, int r, int li, int ri, int i) {
	if (lazy[i] != 0) {
		if (li != ri) {
			lazy[2 * i + 1] += lazy[i];
			lazy[2 * i + 2] += lazy[i];
		}
		stree[i] += lazy[i] * (ri - li + 1);
		lazy[i] = 0;
	}
	if (l == li && r == ri) return stree[i];
	int mid = (li + ri) / 2;
	if (r <= mid) return find(l, r, li, mid, 2 * i + 1);
	if (l >= mid + 1) return find(l, r, mid + 1, ri, 2 * i + 2);
	return find(l, mid, li, mid, 2 * i + 1) + find(mid + 1, r, mid + 1, ri, 2 * i + 2);
}

void set(int l, int r, int d, int li, int ri, int i) {
	if (l == li && r == ri) {
		lazy[i] += d;
		return;
	}
	stree[i] += (long long)d * (r - l + 1);
	int mid = (li + ri) / 2;
	if (r <= mid) set(l, r, d, li, mid, 2 * i + 1);
	else if (l >= mid + 1) set(l, r, d, mid + 1, ri, 2 * i + 2);
	else {
		set(l, mid, d, li, mid, 2 * i + 1);
		set(mid + 1, r, d, mid + 1, ri, 2 * i + 2);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q1, q2;
	cin >> n >> q1 >> q2;

	for (int i = 0; i < n; ++i) cin >> input[i];
	build(0, n - 1, 0);

	int a, b, c, d;
	for (int i = 0; i < q1 + q2; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			b--; c--;
			cout << find(b, c, 0, n - 1, 0) << '\n';
		}
		else {
			cin >> b >> c >> d;
			b--; c--;
			set(b, c, d, 0, n - 1, 0);
		}
	}
}