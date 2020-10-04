#include <iostream>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	if (A + B + C != 180) printf("Error\n");
	else {
		if (A == B) {
			if (B == C) printf("Equilateral\n");
			else printf("Isosceles\n");
		}
		else {
			if (B == C) printf("Isosceles\n");
			else {
				if (A == C) printf("Isosceles\n");
				else printf("Scalene\n");
			}
		}
	}
	return 0;
}