#include <iostream>

int gcd(int m, int n) {
	while (true) {
		if (m > n) m %= n;
		else n %= m;
		if (m == 0 || n == 0) return m + n;
	}
}

int main() {
	int tc, n, arr[100];
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", arr + i);

		long long sum = 0;
		for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
			sum += gcd(arr[i], arr[j]);
		}
		printf("%lld\n", sum);
	}
}