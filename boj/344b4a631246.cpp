#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int t, x, mx = 99, y, my = 99;

	for (int i = 1; i <= n; ++i) {
		cin >> t;
		if (t < mx) {
			mx = t;
			x = i;
		}
	}
	my = t, y = 1;
	for (int i = 2; i <= m; ++i) {
		cin >> t;
		if (t < my) {
			my = t;
			y = i;
		}
	}
	cout << x << ' ' << y;
}