#include <iostream>

int main() {
	int n, arr[1000000];
	long long sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	int b, c;
	scanf("%d %d", &b, &c);

	for (int i = 0; i < n; ++i) {
		sum += 1;
		arr[i] -= b;
		if (arr[i] > 0) sum += (arr[i] - 1) / c + 1;
	}
	printf("%lld\n", sum);
}