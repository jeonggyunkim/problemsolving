#include <iostream>
using namespace std;

int fac(int n) {
	int r = 1;
	for (int i = 1; i <= n; ++i) r *= i;
	return r;
}

int main() {
	double e = 0;
	printf("n e\n- -----------\n");
	for (int i = 0; i < 10; ++i) {
		e += (double)1 / fac(i);
		if (i < 3) printf("%d %.10g\n", i, e);
		else printf("%d %.9lf\n", i, e);
	}
}