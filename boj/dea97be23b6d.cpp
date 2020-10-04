#include <iostream>

int main() {
	long long a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int n = 0, t = b;
	while (t) { n++; t /= 10; }
	for (int i = 0; i < n; ++i) a *= 10;
	a += b;

	n = 0; t = d;
	while (t) { n++; t /= 10; }
	for (int i = 0; i < n; ++i) c *= 10;
	c += d;

	printf("%lld\n", a + c);
}