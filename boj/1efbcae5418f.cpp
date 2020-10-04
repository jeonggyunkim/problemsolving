#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double x, y, c;

double test_c(double d) {
	double a = sqrt(x * x - d * d);
	double b = sqrt(y * y - d * d);
	return a * b / (a + b);
}

int main() {
	while (scanf("%lf %lf %lf", &x, &y, &c) == 3) {
		double low = 0, high = min(x, y), mid, tc;
		while (high - low > 0.000001) {
			mid = (low + high) / 2;
			tc = test_c(mid);
			if (tc > c) low = mid;
			else high = mid;
		}
		printf("%.3lf\n", low);
	}
}