#include <iostream>

int main() {
	int n, k;
	int arr[11];
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) scanf("%d", arr + i);

	int cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		int t = k / arr[i];
		cnt += t; k -= arr[i] * t;
	}
	printf("%d\n", cnt);
}