#include <iostream>

int main() {
	int n;
	long long sum = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) sum += i * (i + 1) / 2;
	for (int i = n - 1; i > 0; i -= 2) sum += i * (i + 1) / 2;

	printf("%lld\n", sum);
}