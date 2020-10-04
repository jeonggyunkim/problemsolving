#include <iostream>

int main() {
	int N, a, b;
	scanf("%d", &N);
	N += (2400 - 2013);
	a = (N + 5) % 12;
	b = (N + 9) % 10;
	printf("%c%c\n", a + 'A', b + '0');

	return 0;
}