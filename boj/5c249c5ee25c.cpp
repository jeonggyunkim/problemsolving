#include <iostream>

int main() {
	int N, T;
	long long sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < 50000; ++i) {
		scanf("%d", &T);
		sum += T;
	}
	printf("%d\n%lld\n", 50000, sum);

	return 0;
}