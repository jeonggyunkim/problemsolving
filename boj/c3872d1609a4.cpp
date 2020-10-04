#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while (cin >> a >> b >> c, a || b || c) {
		if (b > 0) {
			if (c > a && (c - a) % b == 0) cout << (c - a) / b + 1 << '\n';
			else cout << "X\n";
		}
		else {
			if (c < a && (a - c) % -b == 0) cout << (a - c) / -b + 1 << '\n';
			else cout << "X\n";
		}
	}
}