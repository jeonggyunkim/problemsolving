#include <iostream>
#define min(a, b) (a < b ? a : b)

int rec[1001][1001] = {0};

int main() {
	int n, m, t;
	scanf("%d %d", &n, &m);
	int max = -1;
	for (int i = 1; i <= n; ++i) {
		while (getchar() != '\n');
		for (int j = 1; j <= m; ++j) {
			t = getchar();
			if (t & 1) rec[i][j] = min(rec[i - 1][j], min(rec[i][j - 1], rec[i - 1][j - 1])) + 1;
			else rec[i][j] = 0;
			if (rec[i][j] > max) max = rec[i][j];
		}
	}
	printf("%d\n", max * max);
}