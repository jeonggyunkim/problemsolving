#include <iostream>

int main() {
	int n, a, b, cnt = 0;
	scanf("%d %d %d", &n, &a, &b);
	a--; b--;
	do {
		cnt++;
		a >>= 1;
		b >>= 1;
	} while (a != b);
	printf("%d\n", cnt);
}