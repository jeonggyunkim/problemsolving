#include <iostream>
using namespace std;

int main() {
	int x, y, xx, yy;
	cin >> x >> y;
	cin >> xx >> yy;
	x ^= xx; y ^= yy;
	cin >> xx >> yy;
	x ^= xx; y ^= yy;
	cout << x << ' ' << y;
}