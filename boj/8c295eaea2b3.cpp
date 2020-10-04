#include <iostream>
#include <cmath>
#define EPS 1e-5
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int p, q, r;
	p = a;
	q = 2 * b * c;
	r = a * (c * c - a * a + b * b);

	int d = q * q - 4 * p * r;
	if (d < 0) {
		cout << -1;
		return 0;
	}

	double x;
	x = (-q + sqrt(d)) / (2 * p);

	if (x < 0) {
		cout << -1;
		return 0;
	}
	cout << (int)(x + EPS);
}