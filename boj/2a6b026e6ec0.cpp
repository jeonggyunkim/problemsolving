#include <iostream>
#include <cmath>
#define SQ(a) ((a) * (a))
using namespace std;

int main() {
	double a, t;
	cin >> a >> t;

	double r = t / sqrt(3);

	double low = 0, high = t / 2.0, x, y;
	for (int i = 0; i < 50; ++i) {
		x = (low + high) / 2;
		y = sqrt(SQ(r) - SQ(x));
		if (sqrt(SQ(x) + SQ(y + r)) >= a) low = x;
		else high = x;
	}

	double tt = t / (2 * sqrt(3));
	double ans = sqrt((SQ(t / 2 - x) + SQ(y - tt)) * (SQ(x + t / 2) + SQ(y - tt)));
	
	cout.precision(0);
	cout << fixed;
	cout << ans;
}