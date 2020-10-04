#include <iostream>
using namespace std;

int main() {
	int w, h, t, p, q;
	cin >> w >> h >> p >> q >> t;

	int tx = t % (2 * w);
	int ty = t % (2 * h);

	int x, y;

	if (p + tx <= w) {
		x = p + tx;
	}
	else if (p + tx <= 2 * w) {
		x = 2 * w - p - tx;
	}
	else {
		x = p + tx - 2 * w;
	}

	if (q + ty <= h) {
		y = q + ty;
	}
	else if (q + ty <= 2 * h) {
		y = 2 * h - q - ty;
	}
	else {
		y = q + ty - 2 * h;
	}

	cout << x << " " << y << endl;

	return 0;
}