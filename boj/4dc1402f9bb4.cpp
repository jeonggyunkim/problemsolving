#include <iostream>

int main() {
	int tc, n;
	scanf("%d", &tc);

	while (tc--) {
		long long arr[5] = {1, 1, 1, 2, 2}, t;
		scanf("%d", &n);
		if (n <= 5) {
			printf("%lld\n", arr[n - 1]);
			continue;
		}
		for (int i = 0; i < n - 5; ++i) {
			t = arr[0];
			arr[0] = arr[1];
			arr[1] = arr[2];
			arr[2] = arr[3];
			arr[3] = arr[4];
			arr[4] += t;
		}
		printf("%lld\n", arr[4]);
	}
}