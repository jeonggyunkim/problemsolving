#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	ld low = 0, high = b + c;
	for (int i = 0; i < 100; ++i) {
		ld mid = (low + high) / 2;
		if (a * mid + b * sinl(mid) < c) low = mid;
		else high = mid;
	}

	cout.precision(20);
	cout << low;
}