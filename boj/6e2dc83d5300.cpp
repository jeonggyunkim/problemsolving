#include <iostream>

int main() {
	int n, t;
	long long mem[102][102] = {0};
	mem[0][0] = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		scanf("%d", &t);
		if (t == 0 || mem[i][j] == 0) continue;
		if (i + t < n) mem[i + t][j] += mem[i][j];
		if (j + t < n) mem[i][j + t] += mem[i][j];
	}

	printf("%lld\n", mem[n - 1][n - 1]);
}