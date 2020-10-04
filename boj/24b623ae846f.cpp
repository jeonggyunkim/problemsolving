#include <iostream>
#define max(a, b) (a > b ? a : b)

int main() {
	int n, tri[501][501] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= i; ++j) scanf("%d", &tri[i][j]);
	for (int i = 2; i <= n; ++i) for (int j = 1; j <= i; ++j) tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);

	int ans = -1;
	for (int i = 1; i <= n; ++i) ans = max(ans, tri[n][i]);

	printf("%d", ans);
}