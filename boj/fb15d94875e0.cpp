#include <iostream>
using namespace std;

int sum(int i) {
	int ret = 0;
	while (i) {
		ret += i % 10;
		i /= 10;
	}
	return ret;
}

int main() {
	int l, d, x, n = 10001, m = -1;
	cin >> l >> d >> x;
	for (int i = l; i <= d; ++i) {
		if (sum(i) == x) {
			n = min(n, i);
			m = max(m, i);
		}
	}
	cout << n << '\n' << m;
}