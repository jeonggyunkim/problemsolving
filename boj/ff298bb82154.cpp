#include <iostream>
using namespace std;

typedef long long ll;

ll* times(ll* a, ll* b) {
	ll* c = new ll[4];
	c[0] = (a[0] * b[0] + a[1] * b[2]) % 1000000;
	c[1] = (a[0] * b[1] + a[1] * b[3]) % 1000000;
	c[2] = (a[2] * b[0] + a[3] * b[2]) % 1000000;
	c[3] = (a[2] * b[1] + a[3] * b[3]) % 1000000;

	delete[] a;
	delete[] b;

	return c;
}

ll* square(ll* a) {
	ll* c = new ll[4];
	c[0] = (a[0] * a[0] + a[1] * a[2]) % 1000000;
	c[1] = (a[0] * a[1] + a[1] * a[3]) % 1000000;
	c[2] = (a[2] * a[0] + a[3] * a[2]) % 1000000;
	c[3] = (a[2] * a[1] + a[3] * a[3]) % 1000000;

	delete[] a;

	return c;
}

ll* fibmatrix(ll n) {
	ll* a = new ll[4];
	a[0] = 1; a[1] = 1; a[2] = 1; a[3] = 0;

	if (n == 1) return a;
	if (n % 2 == 0) {
		delete[] a;
		return square(fibmatrix(n / 2));
	}
	else {
		return times(square(fibmatrix(n / 2)), a);
	}
}

int main() {
	ll n;
	cin >> n;

	cout << fibmatrix(n)[1];
}