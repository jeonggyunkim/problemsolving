#include <iostream>

void cal(int n, int& two, int& five, bool b) {
	long long i = 2;
	while (i <= n) {
		if (b) two += n / i;
		else two -= n / i;
		i *= 2;
	}
	i = 5;
	while (i <= n) {
		if (b) five += n / i;
		else five -= n / i;
		i *= 5;
	}
}

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	int two = 0, five = 0;
	unsigned int i;

	cal(n, two, five, true);
	cal(m, two, five, false);
	cal(n - m, two, five, false);
	printf("%d\n", two > five ? five : two);
}