#include <iostream>
using namespace std;

int main() {
	long long x, y, z;
	cin >> x >> y;

	z = y * 100 / x;

	if (z >= 99) cout << -1;
	else cout << ((x * z + x - 100 * y) / (99 - z)) + ((x * z + x - 100 * y) % (99 - z) ? 1 : 0);
}