#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double d, t;
	int r;
	
	int test = 0;
	while (cin >> d >> r >> t, r) {
		test++;
		printf("Trip #%d: %.2f %.2f\n", test, M_PI * d * r / 63360, M_PI * d * r * 3600 / t / 63360);
	}
}