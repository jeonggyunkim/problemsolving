#include <iostream>
#include <cmath>

int main() {
	int L, a, b;
	double c, t1, t2;
	scanf("%d %d %d", &L, &a, &b);
	c = sqrt(a * a + b * b);
	t1 = a * L / c;
	t2 = b * L / c;

	printf("%d %d\n", (int)t1, (int)t2);
	return 0;
}