#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, test = 1;
	cout.precision(3);
	cout << fixed;
	while (cin >> a >> b >> c, a || b || c) {
		cout << "Triangle #" << test << '\n';
		test++;
		if (a == -1) {
			if (c * c - b * b > 0) cout << "a = " << sqrt(c * c - b * b);
			else cout << "Impossible.";
		}
		else if (b == -1) {
			if (c * c - a * a > 0) cout << "b = " << sqrt(c * c - a * a);
			else cout << "Impossible.";
		}
		else {
			cout << "c = " << sqrt(a * a + b * b);
		}
		cout << "\n\n";
	}
}