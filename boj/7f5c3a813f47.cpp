#include <iostream>
#define INF 987654321
using namespace std;

int n, ft1[262145], ft2[262145];

void set1(int i, int d) {
	while (i <= n) {
		ft1[i] = min(ft1[i], d);
		i += (i & -i);
	}
}

void set2(int i, int d) {
	i = n + 1 - i;
	while (i <= n) {
		ft2[i] = min(ft2[i], d);
		i += (i & -i);
	}
}

int get(int i, int j) {
	int ret = INF;
	i = n + 1 - i;
	while (i + j != n) {
		if ((i & -i) < (j & -j)) {
			ret = min(ret, ft2[i]);
			i &= i - 1;
		}
		else {
			ret = min(ret, ft1[j]);
			j &= j - 1;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nn, m, t;
	cin >> nn >> m;
	n = 1;
	while (n < nn) n <<= 1;

	for (int i = 1; i <= n; ++i) ft1[i] = ft2[i] = INF;

	for (int i = 1; i <= nn; ++i) {
		cin >> t;
		set1(i, t);
		set2(i, t);
	}

	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << get(a, b) << '\n';
	}
}