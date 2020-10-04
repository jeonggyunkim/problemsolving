#include <iostream>

int main() {
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	n--;
	int a = 1, b = 3, t;
	while (--n) {
		t = b;
		b = (a * 2 + b) % 10007;
		a = t;
	}
	printf("%d\n", b);
}