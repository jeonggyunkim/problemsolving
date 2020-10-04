#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double t1, t2;
	cout << fixed;
	cout.precision(3);
	while (cin >> t1 >> t2) {
		if (t1 < 1e-7) break;
		cout << sqrt(1 - (t2 * t2) / (t1 * t1)) << '\n';
	}
}