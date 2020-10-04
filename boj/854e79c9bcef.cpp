#include <iostream>

int main() {
	int num[10] = {0};
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; ++i) num[i] = 1;

	while (--n) {
		for (int i = 9; i >= 0; --i) {
			int t = 0;
			for (int j = 0; j <= i; ++j) t += num[j];
			num[i] = t % 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; ++i) sum += num[i];

	printf("%d\n", sum % 10007);
}