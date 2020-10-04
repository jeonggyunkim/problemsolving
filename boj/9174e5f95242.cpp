#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, x, y, s, r;
	while (cin >> w >> h >> x >> y >> s >> r, s) {
		double a, b, c, d, e, f;
		a = cos(M_PI * r / 180.0) * (s / 100.0) - 1;
		b = -sin(M_PI * r / 180.0) * (s / 100.0);
		c = -x;
		d = sin(M_PI * r / 180.0) * (s / 100.0);
		e = cos(M_PI * r / 180.0) * (s / 100.0) - 1;
		f = -y;

		cout.precision(2);
		cout << fixed;
		cout << (c * e - b * f) / (a * e - b * d) << ' ';
		cout << (e * f - c * d) / (a * e - b * d) << '\n';
	}
}