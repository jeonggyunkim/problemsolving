#include <iostream>
#include <cmath>
#define sq(a) ((a) * (a))
using namespace std;

int main() {
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if (r1 < r2) swap(r1, r2);

	double dist = sqrt(sq(x1 - x2) + sq(y1 - y2)), area;

	if (dist > r1 + r2) area = 0;
	else if (dist <= r1 - r2) {
		area = M_PI * sq(r2);
	}
	else {
		double c1, c2, s1, s2, t1, t2;
		if (sq(dist) > sq(r1) + sq(r2)) {
			c1 = (sq(r1) + sq(dist) - sq(r2)) / (2 * r1 * dist);
			c2 = (sq(r2) + sq(dist) - sq(r1)) / (2 * r2 * dist);

			s1 = sqrt(1 - sq(c1));
			s2 = sqrt(1 - sq(c2));

			t1 = acos(c1);
			t2 = acos(c2);

			area = sq(r1) * t1 + sq(r2) * t2;

			area -= sq(r1) * s1 * c1;
			area -= sq(r2) * s2 * c2;
		}
		else {
			c1 = (sq(r1) + sq(dist) - sq(r2)) / (2 * r1 * dist);
			c2 = - (sq(r2) + sq(dist) - sq(r1)) / (2 * r2 * dist);

			s1 = sqrt(1 - sq(c1));
			s2 = sqrt(1 - sq(c2));

			t1 = acos(c1);
			t2 = acos(c2);

			area = sq(r1) * t1 + sq(r2) * (M_PI - t2);

			area -= sq(r1) * s1 * c1;
			area += sq(r2) * s2 * c2;
		}
	}
	printf("%.3f\n", area);
}