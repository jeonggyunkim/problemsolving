#include <iostream>

long long c(int n, int r) {
	static long long mem[30][30] = {0};

	if (mem[n][r] > 0) {
		return mem[n][r];
	}
	if (r == 0 || n == r) {
		return mem[n][r] = 1;
	}
	return mem[n][r] = c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N, M;
		scanf("%d %d", &N, &M);

		long long r = c(M, N);

		printf("%lld\n", r);
	}

	return 0;
}