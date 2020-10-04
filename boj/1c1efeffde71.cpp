#include <iostream>
#include <memory.h>

int mem[403][203];

int c(int n, int k) {
	if (mem[n][k] != -1) return mem[n][k];
	if (k == 0 || n == k) return mem[n][k] = 1;
	return mem[n][k] = (c(n - 1, k - 1) + c(n - 1, k)) % 1000000000;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	memset(mem, -1, sizeof(mem));

	printf("%d\n", c(n + k - 1, n));
}