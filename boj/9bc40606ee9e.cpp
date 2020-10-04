#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m;

	int op, x, y = 0;
	long long sum = 0;
	while (m--) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			y ^= x;
			sum += x;
		}
		else if (op == 2) {
			cin >> x;
			y ^= x;
			sum -= x;
		}
		else if (op == 3) cout << sum << '\n';
		else cout << y << '\n';
	}
}