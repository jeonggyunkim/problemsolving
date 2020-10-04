#include <iostream>
#define max(a, b) (a > b ? a : b)

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int sq[101][101];
		int n, t;
		scanf("%d", &n);

		scanf("%d", &t);
		sq[0][0] = t;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				scanf("%d", &t);
				if (j == 0) sq[i][j] = sq[i - 1][j] + t;
				else if (j == i) sq[i][j] = sq[i - 1][j - 1] + t;
				else sq[i][j] = max(sq[i - 1][j - 1], sq[i - 1][j]) + t;
			}
		}
		int m = -1;
		for (int i = 0; i < n; ++i) m = max(m, sq[n - 1][i]);
		printf("%d\n", m);
	}
}
