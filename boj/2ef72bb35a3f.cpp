#include <iostream>

int main() {
	int tc;
	scanf("%d", &tc);

	int a, b;
	while (tc--) {
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
}