#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;
int p = 1;

void upd(int i, long long val) {
	i += p;
	tree[i] = val;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	while (p < n) p *= 2;

	tree.resize(2 * p);

	for (int i = 0; i < n; ++i) cin >> tree[p + i];
	for (int i = p - 1; i >= 1; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];

	long long a, b, c;
	for (int i = 0; i < m + k; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			upd(b, c);
		}
		else {
			b--; c--;
			cout << get(b, c) << '\n';
		}
	}
}