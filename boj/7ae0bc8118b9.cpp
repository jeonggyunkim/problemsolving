#include <iostream>
using namespace std;

int main() {
	long long x0, n;
	cin >> x0 >> n;

	if (__builtin_popcountll(x0) < n) {
		cout << -1;
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		x0 ^= (1LL << (63 - __builtin_clzll(x0)));
		cout << x0 << ' ';
	}
	cout << 0;
}