#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long double b, c, p, q;
	cin >> b >> c >> p >> q;
	cout.precision(20);
	cout << (b + sqrt(b * b + 4 * c)) / 2;
}