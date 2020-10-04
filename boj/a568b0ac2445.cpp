#include <iostream>

int main() {
	int tc;
	scanf("%d", &tc);
	long long koong[70] = {1, 1, 2, 4};
	for (int i = 4; i <= 69; ++i) koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	while (tc--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", koong[n]);
	}
}
