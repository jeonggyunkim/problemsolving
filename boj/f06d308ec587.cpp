#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d;

	e = a * d + b * c, f = b * d;
	cout << e / __gcd(e, f) << ' ' << f / __gcd(e, f);
}