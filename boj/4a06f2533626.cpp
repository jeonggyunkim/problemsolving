#include <iostream>

int main() {
	int a = 1, b, c, d;
	int aaa, s1, s2, s3;

	while (a <= 100) {
		aaa = a * a * a;
		b = 2;
		while ((s1 = b * b * b) < aaa) {
			c = b;
			while ((s2 = s1 + c * c * c) < aaa) {
				d = c;
				while ((s3 = s2 + d * d * d) <= aaa) {
					if (s3 == aaa) printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}