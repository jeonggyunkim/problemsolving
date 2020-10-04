#include <iostream>
#include <cmath>
#define SQ(i) ((i) * (i))
using namespace std;

int x[4], y[4];
double maxd = -1, mind = 1e6;

double dist(int i, int j) {
	return sqrt(SQ(x[i] - x[j]) + SQ(y[i] - y[j]));
}

int main() {
	for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];

	if ((y[2] - y[0]) * (x[1] - x[0]) == (y[1] - y[0]) * (x[2] - x[0])) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < 3; ++i) {
		x[3] = x[0] + x[1] + x[2] - 2 * x[i];
		y[3] = y[0] + y[1] + y[2] - 2 * y[i];

		double d = 0;
		for (int j = 0; j < 3; ++j) {
			if (i != j)	{
				d += dist(i, j);
				d += dist(3, j);
			}
		}
		maxd = max(maxd, d);
		mind = min(mind, d);
	}

	cout.precision(15);
	cout << maxd - mind;
}