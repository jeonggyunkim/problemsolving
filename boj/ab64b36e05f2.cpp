#include <iostream>
using namespace std;

int pisano(int n) {
	int a = 1, b = 1, c, ret = 0;
	do {
		c = b;
		b = (a + b) % n;
		a = c;
		ret++;
	} while (a != 1 || b != 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		int t, n;
		cin >> t >> n;

		cout << test << ' ' << pisano(n) << '\n';
	}
}