#include <iostream>
#define MOD 1000000007
using namespace std;

const int N = 1000010;
int input[N];
long long stree[4 * N];

long long build(int li, int ri, int i) {
	if (li == ri) return stree[i] = input[li];
	long long i1 = build(li, (li + ri) / 2, 2 * i + 1);
	long long i2 = build((li + ri) / 2 + 1, ri, 2 * i + 2);
	return stree[i] = (i1 * i2) % MOD;
}

long long find(int l, int r, int li, int ri, int i) {
	if (l == li && r == ri) return stree[i];
	int mid = (li + ri) / 2;
	if (r <= mid) return find(l, r, li, mid, 2 * i + 1);
	if (l >= mid + 1) return find(l, r, mid + 1, ri, 2 * i + 2);
	return (find(l, mid, li, mid, 2 * i + 1) * find(mid + 1, r, mid + 1, ri, 2 * i + 2)) % MOD;
}

long long set(int ind, int d, int li, int ri, int i) {
	if (ind < li || ind > ri) return stree[i];
	if (li == ri) {
		if (li == ind) stree[i] = d;
		return stree[i];
	}
	int mid = (li + ri) / 2;
	return stree[i] = (set(ind, d, li, mid, 2 * i + 1) * set(ind, d, mid + 1, ri, 2 * i + 2)) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) cin >> input[i];
	build(0, n, 0);

	int a, b, c;
	while (m || k) {
		cin >> a >> b >> c;
		if (a == 1) {
			set(b, c, 0, n, 0);
			m--;
		}
		else {
			cout << find(b, c, 0, n, 0) << '\n';
			k--;
		}
	}
}