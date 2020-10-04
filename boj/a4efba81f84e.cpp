#include <iostream>

int main() {
	int s = 0, p = 3, q = 3, n;
	scanf("%d", &n);
	if (n & 1) printf("0\n");
	else {
		while (n != 2) {
			q = p * 3 + 2 * s + 2;
			s += p; p = q;
			n -= 2;
		}
		printf("%d\n", q);
	}
}