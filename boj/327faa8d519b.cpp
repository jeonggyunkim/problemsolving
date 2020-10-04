#include <iostream>

int main() {
	int n;
	scanf("%d", &n);

	int num[10] = {0}, temp[10];
	for (int i = 1; i < 10; ++i) num[i] = 1;

	while (--n) {
		for (int i = 0; i < 10; ++i) temp[i] = num[i];
		for (int i = 0; i < 10; ++i) {
			if (i == 0) num[0] = temp[1];
			else if (i == 9) num[9] = temp[8];
			else num[i] = (temp[i - 1] + temp[i + 1]) % 1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += num[i];
		sum %= 1000000000;
	}
	printf("%d\n", sum);
}