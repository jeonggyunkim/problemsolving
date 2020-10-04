#include <iostream>
#define max(a, b) (a > b ? a : b)

int num[1002][1002] = {0};

int main() {
	int n, m, t;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		scanf("%d", &t);
		num[i][j] = t + max(num[i][j], max(num[i - 1][j], num[i][j - 1]));
	}
	printf("%d\n", num[n][m]);
}