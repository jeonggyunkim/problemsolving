#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;

	for (int i = 0; i < 100000; ++i) {
		double aa, bb;
		aa = (a + b) / 2;
		bb = 2 * a * b / (a + b);
		a = aa; b = bb;
	}

	cout.precision(15);
	cout << fixed;
	cout << a << ' ' << b;
}