#include <iostream>

int main() {
	int val[301][301];
	int sum[301][301] = {0};
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		scanf("%d", &val[i][j]);
		sum[i][j] = val[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	}

	int k, a, b, c, d;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]);
	}
}