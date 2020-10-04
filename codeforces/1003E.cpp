#include <bits/stdc++.h>
#define INF 500000
using namespace std;

int ind, n, k;

void build_tree(int p, int d, int pos) {
	if (d == 0) return;
	for (int i = 0; i < pos; ++i) {
		if (ind > n) return;
		cout << p << ' ' << ind++ << '\n';
		build_tree(ind - 1, d - 1, k - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d;
	cin >> n >> d >> k;

	if (k == 1) {
		if (d == 1 && n == 2) cout << "YES\n1 2";
		else cout << "NO";
		return 0;
	}

	if (n <= d) {
		cout << "NO";
		return 0;
	}

	long long maxnode = 0;
	if (k == 2) maxnode = d + 1;
	else {
		long long kpow[20] = {1};
		for (int i = 1; i < 20; ++i) kpow[i] = kpow[i - 1] * (k - 1);

		for (int i = 0; i <= d; ++i) {
			maxnode += kpow[min(i, d - i)];
			if (maxnode >= INF) break;
		}
	}
	if (n > maxnode) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (int i = 0; i < d; ++i) {
		cout << i + 1 << ' ' << i + 2 << '\n';
	}
	ind = d + 2;
	for (int i = 0; i < d; ++i) {
		build_tree(i + 1, min(i, d - i), k - 2);
	}
}