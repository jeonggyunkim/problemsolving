#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		long long a = 0, b = 1, c;
		int p, q;
		cin >> p >> q;

		while (p--) {
			c = b;
			b = (a + b) % q;
			a = c;
		}

		cout << "Case #" << test << ": " << a % q << '\n';
	}
}