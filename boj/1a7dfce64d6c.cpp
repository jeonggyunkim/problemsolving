#include <iostream>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", ((B - A) > (C - B) ? B - A : C - B) - 1);
	return 0;
}